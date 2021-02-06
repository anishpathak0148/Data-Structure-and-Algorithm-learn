#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n<=1)
        return n;
    return fibo(n-1) + fibo(n-2);
}
main()
{
    int i;
    cout<<"Fibonacci Series up to 10 digits : ";
    for(i=1;i<=10;i++)
        cout<<fibo(i)<<"  ";
}
