#include <iostream>
using namespace std;

struct Node{
	int data;
	struct Node* link;
};

struct Node* top;

void push(int data)
{
	struct Node* temp;
	temp = new Node();
	if (!temp)
	{
	cout << "\nHeap Overflow";
	exit(1);
	}
	temp->data = data;
	temp->link = top;
	top = temp;
}

void display() 
{
    struct Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);
    cout<<"Stack elements are: ";
    display();
}