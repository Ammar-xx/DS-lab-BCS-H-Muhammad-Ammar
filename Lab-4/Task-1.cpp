#include <iostream>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the size of the array\n";
    cin>>n;
    int array[100];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element at the "<<i+1<<" position: ";
        cin>>array[i];
    }
    int target;
    cout<<"Enter the number you want to find in the array: ";
    cin>>target;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(array[i]==target)
        {
            cout<<"The target element is at index: "<<i<<endl;
            count=1;
            break;
        }
    }
    if(!count)
    {
        cout<<"Target element is not present in the array\n";
    }
}