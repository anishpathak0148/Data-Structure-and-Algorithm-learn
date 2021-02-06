#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
//Time Complexity: O(n/2) => O(n)
void AllFactor(int n)
{
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0)
            cout<<i<<" ";
    }
    cout<<n<<endl;
}
// Time complexity: O(sqrt(n)+log(n)) => O(sqrt(n)). Space Complexity: O(sqrt(n));
void AllFactorOptimized(int n)
{
    int x = sqrt(n);//It takes log2(n) time.
    vector<int>v;
    for(int i=1;i<x;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
        }
    }
    int len = v.size();
    if(n%x==0)
    {
        v.push_back(x);
    }

    for(int i=len-1;i>=0;i--)
    {
        v.push_back(n/v[i]);
    }
    //now print the factor..
    len = v.size();
    for(int i=0;i<len;i++)
    {
        cout<<v[i]<<" ";
    }
    v.clear();
}
main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    cout<<"All factors of "<<n<<" is:"<<endl;
    AllFactor(n);
    cout<<endl<<endl;
    AllFactorOptimized(n);
}
