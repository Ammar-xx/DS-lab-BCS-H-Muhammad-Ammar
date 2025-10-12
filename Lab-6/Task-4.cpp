#include <iostream>
using namespace std;

#define MAX_SIZE 5

int front = -1, rear = -1;
int arr[MAX_SIZE];

bool isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(int value) 
{
    if (isFull()) {
        cout << "Queue is full, cannot enqueue " << value << endl;
        return;
    }

    if (isEmpty()) 
	{
        front = rear = 0;
    } 
	else 
	{
        rear = (rear + 1) % MAX_SIZE;
    }

    arr[rear] = value;
    cout << "Enqueued: " << value << endl;
}

int dequeue() {
    if (isEmpty()) 
	{
        cout << "Queue is empty, cannot dequeue" << endl;
        return -1;
    }

    int removed = arr[front];

    if (front == rear) 
	{
        front = rear = -1;
    } 
	else 
	{
        front = (front + 1) % MAX_SIZE;
    }

    return removed;
}

void display() 
{
    if (isEmpty())
	{
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue contents: ";
    int i = front;
    while (true) 
	{
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  

    display();

    cout << "Dequeued: " << dequeue() << endl;
    cout << "Dequeued: " << dequeue() << endl;

    display();

    enqueue(60);
    enqueue(70);  

    display();

    enqueue(80); 

    while (!isEmpty()) 
	{
        cout << "Dequeued: " << dequeue() << endl;
    }

    display();
}
