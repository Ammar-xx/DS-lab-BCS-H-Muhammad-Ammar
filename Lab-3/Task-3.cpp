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

Node* reverse(Node* head,int k)
{
    Node* temp=head;
    for(int i=0;i<k;i++)
    {
        if(temp==nullptr)
        {
            return head;
        }
        temp=temp->next;
    }
    Node* prev=reverse(temp,k);
    temp=head;
    Node* next;
    for(int i=0;i<k;i++)
    {
        next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
    }
    return prev;
}
void printList(Node* head) 
        {
            Node* temp = head;
            while (temp) 
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }
int main()
{
    Linkedlist l;
    int n;
    cout<<"Enter the number of nodes you want in the linked list: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        l.pushback();
    }
    int k;
    cout<<"Enter the groups size: ";
    cin>>k;
    Node* head=reverse(l.getHead(),k);
    printList(head);
}