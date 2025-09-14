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
    int target;
    cout<<"Enter the number you want to find in the array: ";
    cin>>target;
    for (int i = 1; i < s; i++) {
        int a = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > a) 
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j+1] = a;
    }
    cout<<"Sorted array\n";
    for(int i=0;i<s;i++)
    {
        cout<<array[i]<<" ";
    }
    int c = 0, d = s - 1;
    int count=0;
    while (c <= d) 
    {
        int mid = c + (d - c) / 2; 

        if (array[mid] == target)
        {
            cout<<"The index of the target element: "<<mid<<endl;
            count=1;
            break;
        }
        else if (array[mid] < target)
        {
            c = mid + 1; 
        }
        else
        {
            d = mid - 1;
        } 
    }
    if(!count)
    {
        cout<<"Target element not found in the array\n";
    }
}