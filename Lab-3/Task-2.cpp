#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        next=nullptr;
    }
    Node(int d)
    {
        data=d;
        next=nullptr;
    }
};
class Linkedlist{
    Node* head;
    public:
        Linkedlist()
        {
            head=nullptr;
        }
        void pushback(int d)
        {
            Node* n=new Node(d);
            if(head==nullptr)
            {
                head=n;
            }
            else
            {
                Node* temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=n;
            }
        }
        void printList() 
        {
        Node* temp = head;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
        }
        Node* getHead()
        {
            return head;
        }
};

int main()
{
    Linkedlist l;
    Linkedlist s;
    l.pushback(1);
    s.pushback(2);
    l.pushback(3);
    s.pushback(4);
    l.pushback(5);
    s.pushback(6);
    cout<<"List A: ";
    l.printList();
    cout<<"List B: ";
    s.printList();
    Node* temp1=l.getHead();
    Node* temp2=s.getHead();
    Node* start=new Node(0);
    Node* temp=start;
    while(temp1!=nullptr && temp2!=nullptr)
    {
        if(temp1->data>=temp2->data)
        {
            temp->next=temp2;
            temp2=temp2->next;
        }
        else
        {
            temp->next=temp1;
            temp1=temp1->next;
        }
        temp=temp->next;
    }
    Node* head=start->next;
    cout<<"Merged List: ";
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
} 