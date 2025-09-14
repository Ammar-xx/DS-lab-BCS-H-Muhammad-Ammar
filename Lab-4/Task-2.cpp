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
    cout<<"Unsorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    int count,temp;
    for(int i=0;i<n-1;i++)
    {
        count=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
                count=0;
            }
        }
        if(count)
        {
            break;
        }
    }
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }

}