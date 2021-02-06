#include<iostream>
#include<cmath>
using namespace std;
//Time Complexity: O(n)
void AllPrimeFactor(int n)
{
    cout<<"Prime Factor"<<"  "<<"Frequency"<<endl;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            int ct=0;
            while(n%i==0)
            {
                n = n/i;
                ct++;
            }
            cout<<i<<" \t\t "<<ct<<endl;
        }
    }
}
//Time Complexity: O(sqrt(n)).
void AllPrimeFactor_optimized(int n)
{
    cout<<"Prime Factor"<<"  "<<"Frequency"<<endl;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int ct=0;
            while(n%i==0)
            {
                n = n/i;
                ct++;
            }
            cout<<i<<" \t\t "<<ct<<endl;
        }
    }
    if(n!=1)
    {
        cout<<n<<" \t\t "<<1<<endl;
    }
}
main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    AllPrimeFactor(n);
    cout<<endl<<endl;
    AllPrimeFactor_optimized(n);

}
