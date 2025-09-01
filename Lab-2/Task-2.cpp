#include <iostream>
using namespace std;

int main()
{
	int** array=new int*[5];
	for(int i=0;i<5;i++)
	{
		array[i]=new int[6];
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<6;j++)
		{
			array[i][j]=0;
		}
	}
	int choice;
	while(1)
	{
		cout<<"1.Occupy seat\n2.Print the array and Exit\nEnter your choice: ";
		cin>>choice;
		if(choice==1)
		{
			int row,column;
			while(1)
			{
				cout<<"Enter the row and column of the seat: ";
				cin>>row>>column;
				if(row>0 && row<=5 && column>0 && column<=6)
				{
					if(array[row][column]==0)
					{
						array[row][column]=1;
					}
					else
					{
						cout<<"The seat is already occupied\n";
					}
					break;
				}
				else
				{
					cout<<"Row and column number is out of bounds.Try again\n";
				}
			}
		}
		else if(choice==2)
		{
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<6;j++)
				{
					cout<<array[i][j]<<" ";
				}
				cout<<endl;
				delete array[i];
			}
			break;
		}
	}
	delete[] array;
}