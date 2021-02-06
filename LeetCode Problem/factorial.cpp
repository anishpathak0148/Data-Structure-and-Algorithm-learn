#include<iostream>
using namespace std;
main()
{
    long long int n;
    cout<<"Enter Input:";
    cin>>n;
    long long int fact=1;
    for(int i=1;i<=n;i++)
    {

        fact = fact*i;
    }
    cout<<"\nResult:"<<fact;
}
