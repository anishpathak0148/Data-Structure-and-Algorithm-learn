/*
Program based upon Dynamic Programming.
....Overlapping Subproblems
    ....Tabulation(Bottom to Up)
*/
#include<iostream>
using namespace std;
int fibo(int n)
{
    int f[n+1];
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1] + f[i-2];
    }
    return f[n];
}
main()
{
    int i,n;
    cout<<"\nEnter n:";
    cin>>n;
    cout<<"Fibonacci Series up to "<<n<<" digits : ";
    for(i=1;i<=n;i++)
        cout<<fibo(i)<<"  ";
}
