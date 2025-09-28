#include <iostream>
using namespace std;
void printNumbers(int n) //Represeting direct recursion
{
    if(n<=0) 
    {
        return;
    }
    cout<<n<<" ";
    printNumbers(n-1);
}

void B(int n);

void A(int n) //representing indirect recursion
{  
    if(n<=0) 
    {
        return;
    }
    cout<<"A"<<n<<" ";
    B(n-1);
}
void B(int n) //representing indirect recursion
{  
    if(n<=0) 
    {
        return;
    }
    cout<<"B"<<n<<" ";
    A(n-2);
}
int main(){
    int n;
    cout<<"Enter the number for direct recursion: ";
    cin>>n;
    printNumbers(n);
    cout<<"\nEnter the number for indirect recursion: ";
    cin>>n;
    A(n);
    cout<<"\n";
}
