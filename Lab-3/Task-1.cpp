#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
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

        bool checkPalindrome(int n)
        {
            int* array=new int[n];
            int* rev=new int[n];
            Node* temp=head;
            for(int i=0;i<n;i++)
            {
                array[i]=temp->data;
                temp=temp->next;
            }
            int j=0;
            for(int i=n-1;i>=0;i--)
            {
                rev[j]=array[i];
                j++;
            }
            for(int i=0;i<n;i++)
            {
                if(array[i]!=rev[i])
                {
                    delete[] array;
                    delete[] rev;
                    return false;
                }
            }
            delete[] array;
            delete[] rev;
            return true;
        }

};
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
    cout<<"Does the linked list has Palindrome: ";
    bool i=l.checkPalindrome(n);
    if(i)
    {
        cout<<"True";
    }
    else 
    {
        cout<<"False";
    }
}