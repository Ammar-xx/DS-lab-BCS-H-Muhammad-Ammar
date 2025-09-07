#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node()
        {
            data=0;
            next=nullptr;
            prev=nullptr;
        }
        Node(int v)
        {
            data=v;
            next=nullptr;
            prev=nullptr;
        }
};

class LinkedList{
    Node* head;
    public:
        LinkedList()
        {
            head=nullptr;
        }
        void pushback()
        {
            int d;
            cout<<"Enter the number you want to store in the Node: ";
            cin>>d;
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

Node* circular(Node* head)
{
    Node* temp=head;
    if(temp==nullptr)
    {
        return nullptr;
    }
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=head;
    return head;
}

Node* doubly(Node* head)
{
    Node* temp1=head;
    if(temp1==nullptr)
    {
        return nullptr;
    }
    int c=0;
    Node* temp2=head;
    while(temp2->next!=nullptr)
    {
        if(c==0)
        {
            temp1->prev=nullptr;
            temp1=temp1->next;
            c++;
        }
        else
        {
            temp1->prev=temp2;
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return head;
}
void printForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printBackward(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void printCircular(Node* head, int steps) {
    if (head == nullptr) return;

    Node* temp = head;
    for (int i = 0; i < steps; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main()
{
    LinkedList l1,l2;
    int n1,n2;
    cout<<"Enter the number of nodes you want in the linked list to be converted into doubly linked list: ";
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        l1.pushback();
    }
    cout<<"Enter the number of nodes you want in the linked list to be converted into circular linked list: ";
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        l2.pushback();
    }
    cout<<"Converting singly linked list into doubly linked list\n";
    Node* head1=doubly(l1.getHead());
    cout<<"Singly linked list successfully converted into doubly linked list\n";
    cout << "Forward: ";  printForward(head1);
    cout << "Backward: "; printBackward(head1);
    cout<<"Converting singly linked list into circular linked list\n";
    Node* head2=circular(l2.getHead());
    cout<<"Singly linked list successfully converted into circular linked list\n";
    cout << "Circular (2 rounds): "; printCircular(head2, n2*2);
}