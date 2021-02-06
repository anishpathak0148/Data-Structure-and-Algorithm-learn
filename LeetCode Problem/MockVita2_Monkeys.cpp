#include<iostream>
#include<vector>
using namespace std;
long getTime(vector<long>v1,vector<long>v2,vector<long>v3,long t)
{
    if(v1==v2)
        return t;
    for(int i=0;i<v1.size();i++)
    {
        int j=v1[i];
        v3[j-1] = v2[i];
    }
    t++;
    t = getTime(v1,v3,v2,t);
    return t;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long>v1(n);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        vector<long>v2(n);
        for(int i=0;i<v1.size();i++)
        {
            int j=v1[i];
            v2[j-1] = j;
        }
        vector<long>v3(n,0);
        long result = getTime(v1,v2,v3,1);
        cout<<result<<endl;
    }
}
