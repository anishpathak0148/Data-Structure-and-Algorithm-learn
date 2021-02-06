#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//This function takes: O(sqrt(n)) time.
bool isPrime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
//Time Complexity: O(n*sqrt(n)).
void printPrimeNumber(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
            cout<<i<<"  ";
    }
}
//Optimized solution based on Sieve of Eratosthenes Algorithm..
//Time Complexity: O(n*log(log(n))). Space Complexity: O(n).
void printPrime_Optimize(int n)
{
    vector<bool>arr(n+1,true);
    arr[0]=arr[1]=false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(arr[i]==true)
        {
            for(int j=2;i*j<=n;j++)
            {
                arr[i*j] = false;
            }
        }
    }
    //now print those index from prime array whose value is true.
    int ct=0;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]){
            //cout<<i<<"  ";
            ct++;
        }
    }
    cout<<"\nTotal Prime no between 1 to "<<n<<" is:"<<ct;
}
main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    cout<<"All Prime number between 1 to "<<n<<" is:"<<endl;
    //printPrimeNumber(n);
    cout<<endl<<endl;
    printPrime_Optimize(n);
}
