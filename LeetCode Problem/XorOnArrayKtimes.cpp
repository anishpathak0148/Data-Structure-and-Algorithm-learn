#include<iostream>
#include<vector>
using namespace std;
vector<int> PerformXOR(vector<int>v1)
{
    vector<int>v;
    for(int i=0;i<v1.size()-1;i++)
    {
        v.push_back(v1[i]^v1[i+1]);
    }
    return v;
}
vector<int> Perform_XOR(vector<int>v1,int range)
{
    vector<int>v;
    for(int i=0;i<v1.size()-1;i++)
    {
        v.push_back(v1[i]^v1[i+1]);
    }
    return v;
}
main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int m;
    cin>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int>res=v;
    int range = n-k;
    while(k--)
    {
        res = PerformXOR(res);
    }
    cout<<res[m];
}
