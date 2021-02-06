#include<iostream>
#include<vector>
using namespace std;
void SumOfSubset(vector<int>s,int m)
{
    int n=s.size();
    char arr[n][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0)
                arr[i][j]='T';
            else if(i==0)
            {
                if(s[i]==j)
                    arr[i][j]='T';
                else
                    arr[i][j]='F';
            }
            else if(j<s[i])
                arr[i][j]=arr[i-1][j];
            else if((j-s[i])>=0)
            {
                if(arr[i-1][j]=='F')
                    arr[i][j]=arr[i-1][j-s[i]];
                else
                    arr[i][j]=arr[i-1][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<"\t"<<arr[i][j];
        cout<<"\n";
    }
}
main()
{
    vector <int> set={2,3,7,8,10};
    int sum=11;
    SumOfSubset(set,sum);
}
