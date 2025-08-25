#include <iostream>
using namespace std;

class bankAccount{
	public:
		float balance;
		
	bankAccount(){
	balance=0;}
	bankAccount(float b)
	{
		balance=b;
	}
	bankAccount(const bankAccount &other)
	{
		balance=other.balance;
	}
};

int main()
{
	bankAccount account1;
	cout<<"Account 1 balance: "<<account1.balance<<endl;
	bankAccount account2(1000);
	cout<<"Account 2 balance: "<<account2.balance<<endl;
	bankAccount account3=account2;
	account3.balance=account3.balance-300;
	cout<<"Account 3 balance: "<<account3.balance<<endl;
}