#include <iostream>
using namespace std;

int main()
{
	int size;
	cout<<"Enter the size of the array: ";
	cin>>size;
	int* array=new int[size];
	for(int i=0;i<size;i++)
	{
		array[i]=0;
	}
	int choice;
	while(1)
	{
		cout<<"1.Update value\n2.Print the array and Exit\nEnter your choice: ";
		cin>>choice;
		if(choice==1)
		{
			int index;
			while(1)
			{
				cout<<"Enter the index: ";
				cin>>index;
				if(index>=0 && index<size)
				{
					cout<<"Enter the value: ";
					cin>>array[index];
					break;
				}
				else
				{
					cout<<"Index out of bounds.Try again\n";
				}
			}
		}
		else if(choice==2)
		{
			for(int i=0;i<size;i++)
			{
				cout<<array[i]<<endl;
			}
			break;
		}
	}
	delete[] array;
}