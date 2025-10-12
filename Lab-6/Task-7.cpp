#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Process 
{
    int id;
    int priority;
};

void printProcess(const Process& p) 
{
    cout << "(ID:" << p.id << ", Priority:" << p.priority << ")";
}

int main() 
{
    queue<Process> arrivalQueue;
    stack<Process> execStack;

    arrivalQueue.push({1, 2});
    arrivalQueue.push({2, 5});
    arrivalQueue.push({3, 1});
    arrivalQueue.push({4, 4});
    arrivalQueue.push({5, 3});

    cout << "Processes in arrival order (Queue):\n";
    queue<Process> tempQ = arrivalQueue;
    while (!tempQ.empty()) 
	{
        printProcess(tempQ.front());
        cout << " ";
        tempQ.pop();
    }
    cout << "\n\n";

    while (!arrivalQueue.empty()) 
	{
        Process p = arrivalQueue.front();
        arrivalQueue.pop();

        if (execStack.empty()) 
		{
            execStack.push(p);
        } 
		else 
		{
            stack<Process> tempStack;
            while (!execStack.empty() && execStack.top().priority >= p.priority) 
			{
                tempStack.push(execStack.top());
                execStack.pop();
            }
            execStack.push(p);
            while (!tempStack.empty()) 
			{
                execStack.push(tempStack.top());
                tempStack.pop();
            }
        }
    }

    cout << "Execution order (Stack - LIFO by priority):\n";
    while (!execStack.empty()) 
	{
        printProcess(execStack.top());
        cout<<endl;
        execStack.pop();
    }

    return 0;
}
