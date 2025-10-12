#include <iostream>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool isRightAssociative(char op) 
{
    return op == '^';
}

bool isDigit(char c) 
{
    return c >= '0' && c <= '9';
}

string reverseString(string s) 
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    return s;
}

string infixToPrefix(string infix) 
{
    string rev = "";
    for (int i = infix.length() - 1; i >= 0; i--) 
	{
        if (infix[i] == '(') rev += ')';
        else if (infix[i] == ')') rev += '(';
        else rev += infix[i];
    }

    stack<char> st;
    string prefix = "";

    for (char c : rev) 
	{
        if (isDigit(c)) 
		{
            prefix += c;
        } 
		else if (c == '(') 
		{
            st.push(c);
        } 
		else if (c == ')') 
		{
            while (!st.empty() && st.top() != '(') 
			{
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } 
		else if (isOperator(c)) 
		{
            while (!st.empty() && isOperator(st.top())) 
			{
                char topOp = st.top();
                int precTop = getPrecedence(topOp);
                int precCurr = getPrecedence(c);
                if (precTop > precCurr || (precTop == precCurr && !isRightAssociative(c))) {
                    prefix += topOp;
                    st.pop();
                } 
				else break;
            }
            st.push(c);
        }
    }

    while (!st.empty()) 
	{
        prefix += st.top();
        st.pop();
    }

    return reverseString(prefix);
}

int evaluatePrefix(string prefix) {
    stack<int> st;
    for (int i = prefix.length() - 1; i >= 0; i--) 
	{
        char c = prefix[i];
        if (isDigit(c)) 
		{
            st.push(c - '0');
        } 
		else if (isOperator(c)) 
		{
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            int res = 0;
            switch (c) 
			{
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': 
				{
                    res = 1;
                    for (int j = 0; j < b; j++) res *= a;
                    break;
                }
            }
            st.push(res);
        }
    }
    return st.top();
}

int main() 
{
    string infix;
    cout << "Enter infix expression (single digits, operators + - * / ^): ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    int result = evaluatePrefix(prefix);
    cout << "Evaluated result: " << result << endl;

    return 0;
}
