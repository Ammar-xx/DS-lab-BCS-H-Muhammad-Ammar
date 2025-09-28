#include <iostream>
using namespace std;
int Factorial(int n)
{
    if(n<=1) 
    {
        return 1;
    }
    return n*Factorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter the number you want factorial of: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<Factorial(n)<<".\n";
}
