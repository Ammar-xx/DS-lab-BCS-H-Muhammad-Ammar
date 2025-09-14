#include <iostream>
using namespace std;

int main()
{
    int s;
    cout<<"Enter the size of the array\n";
    cin>>s;
    int array[100];
    for(int i=0;i<s;i++)
    {
        cout<<"Enter the element at the "<<i+1<<" position\n";
        cin>>array[i];
    }
    int min,temp; 
    for(int i=0;i<s;i++)
    {
        min=i;
        for(int j=i+1;j<s;j++)
        {
            if(array[j]<array[min])
            {
                min=j;
            }
        }
        temp=array[i];
        array[i]=array[min];
        array[min]=temp;
    }

    cout<<"Sorted array\n";
    for(int i=0;i<s;i++)
    {
        cout<<array[i]<<" ";
    }
}