/*
Program based upon Dynamic Programming.
....Overlapping Subproblems
    ....Memorization(TOP to DOWN)
*/

#include<iostream>
using namespace std;
#define max 30
int MT[max];
void initialize()
{
    for(int i=0;i<max;i++)
        MT[i]=-1;
}

int fibo(int n)
{
    if(MT[n]!=-1)
        return MT[n];
    else
    {
        if(n<=1)
            return MT[n]=n;
        else
            return MT[n] = fibo(n-1) + fibo(n-2);
    }
}
main()
{
    int i,n;
    cout<<"Enter n:";
    cin>>n;
    initialize();
    cout<<"\nFibonacci Series up to "<<n<<" digits : ";
    for(i=1;i<=n;i++)
        cout<<fibo(i)<<"  ";
}
