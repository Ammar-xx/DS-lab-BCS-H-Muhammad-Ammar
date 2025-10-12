#include <iostream>
using namespace std;

class Stack{
	int top;
	public:
	int* array;
	int size;

	Stack(int s)
	{
		size=s;
		array=new int[size];
		top=-1;
	}
	~Stack()
	{
		delete[] array;
	}
	void push(int n)
	{
		if(size-1<=top)
		{
			cout<<"Stack overflow\n";
			return;
		}
		else
		{
			top++;
			array[top]=n;
			cout<<"Element added successfully in the stack\n";
		}
	}
	void pop()
	{
		if(top==-1)
		{
			cout<<"Stack underflow. Stack is empty\n";
			return;
		}
		else
		{
			top--;
			cout<<"Top Element removed successfully\n";
		}
	}

	int peek()
	{
		if(size==-1)
		{
			cout<<"Error. Stack is empty\n";
			return -1;
		}
		else
		{
			return array[top];
		}
	}

	void display()
	{
		cout<<"Stack Elements: ";
		for(int i=size;i>=0;i--)
		{
			cout<<array[top]<<" ";
		}
	}
};

int main()
{
    Stack stack(3);

    stack.push(100);
    stack.push(200);
    stack.push(300);


    stack.display();
    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    stack.display();
    cout << "Top element: " << stack.peek() << endl;

}