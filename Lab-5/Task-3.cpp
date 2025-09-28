#include <iostream>
using namespace std;

int Tail(int n,int total)
{
    if(n==0) 
    {
        return total;
    }
    return Tail(n-1,total+n);
}
int nonTail(int n)
{
    if(n==0) 
    {
        return 0;
    }
    
    return n + nonTail(n-1);
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Tail sum: "<<Tail(n,0)<<"\n";
    cout<<"Non-tail sum: "<<nonTail(n)<<"\n";
    return 0;
}
