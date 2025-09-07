#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    Node()
    {
        data=0;
        next= nullptr;
        child=nullptr;
    }
    Node(int v)
    {
        data=v;
        next= nullptr;
        child=nullptr;
    }

    void setChild(Node* n)
    {
        child=n;
    }
};

class LinkedList{
    Node* head;
    public:
        LinkedList()
        {
            head=nullptr;
        }
        void pushback(int v)
        {
            Node* n=new Node(v);
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

        Node* getHead()
        {
            return head;
        }

};

void printList(Node* head) 
        {
            Node* temp = head;
            while (temp ) 
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

Node* flatten(Node* head)
{
    Node* temp=head;
    Node* next;
    while(temp!=nullptr)
    {
        if(temp->child!=nullptr)
        {
            next=temp->next;
            temp->next=flatten(temp->child);
            temp->child=nullptr;
            Node* tail=temp->next;
            while(tail->next!=nullptr)
            {
                tail=tail->next;
            }
            tail->next=next;
            temp=next;
        }
        else
        {
            temp=temp->next;
        }
    }
    return head;
}

int main()
{
    LinkedList l1,l2;
    for(int i=1;i<=3;i++)
    {
        l1.pushback(i);
    }
    for(int i=4;i<=5;i++)
    {
        l2.pushback(i);
    }
    Node* temp=l1.getHead();
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    cout<<"Before flattening:\n";
    printList(l1.getHead());
    cout<<"  ";
    printList(l2.getHead());
    temp->setChild(l2.getHead());
    Node* head=flatten(l1.getHead());
    cout<<"After flattening: ";
    printList(head);
}