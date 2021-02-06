#include<iostream>
#include<vector>
using namespace std;
void knapsack_result(vector<int>P, vector<int>wt, int m)
{
    int n=P.size()-1;
    int DP[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                DP[i][j]=0;
            else if(wt[i]<=j)
            {
                DP[i][j]= max(DP[i-1][j] , DP[i-1][j-wt[i]] + P[i]);
            }
            else
                DP[i][j]= DP[i-1][j];
        }
    }
    cout<<"DP Table is:"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<"\t"<<DP[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n\nMaximum Profit is: "<<DP[n][m]<<endl;

    cout<<"\n\nSolution of this Problem is:"<<endl;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(DP[i][j] == DP[i-1][j])
        {
            cout<<wt[i]<<" = 0"<<endl;
            i--;
        }
        else{
            cout<<wt[i]<<" =1"<<endl;
            //i--;
            j=j-wt[i];
            --i;
        }
    }
}
main()
{
    vector<int> P={0,1,2,5,6}, wt={0,2,3,4,5};
    int m=8;
    cout<<"P\twt"<<endl;
    for(int i=0;i<P.size();i++)
    {
        cout<<P[i]<<"\t"<<wt[i]<<endl;
    }
    cout<<"\n";
    knapsack_result(P,wt,m);
}
