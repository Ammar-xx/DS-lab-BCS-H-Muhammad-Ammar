#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string infix) 
{
    stack<char> st;
    string postfix = "";
    for (char c : infix) 
	{
        if (c == ' ') continue;
        if (isdigit(c)) 
		{
            postfix += c;
        } 
		else if (c == '(') 
		{
            st.push(c);
        } 
		else if (c == ')') 
		{
            while (!st.empty() && st.top() != '(') 
			{
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } 
		else if (isOperator(c)) 
		{
            while (!st.empty() && precedence(st.top()) >= precedence(c)) 
			{
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) 
	{
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(string postfix) 
{
    stack<int> st;
    for (char c : postfix) 
	{
        if (isdigit(c)) 
		{
            st.push(c - '0');
        } 
		else 
		{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res = 0;
            if (c == '+') res = a + b;
            else if (c == '-') res = a - b;
            else if (c == '*') res = a * b;
            else if (c == '/') res = a / b;
            st.push(res);
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression (single digits, + - * /): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;
}
