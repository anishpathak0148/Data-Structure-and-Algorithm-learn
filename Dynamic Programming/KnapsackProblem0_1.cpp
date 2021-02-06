#include<bits/stdc++.h>
using namespace std;
// This techniques is based on Recursion...But it takes more time O(2^n) as repeated work is done..
int KnapsackUsingRec(int wt[], int profit[], int n, int W)
{
    //Base condition..
    if(n==0 || W==0)
        return 0;
    if(wt[n-1] <= W)
    {
        return max(profit[n-1] + KnapsackUsingRec(wt,profit,n-1,W-wt[n-1]), KnapsackUsingRec(wt,profit,n-1,W));
    }
    else if(wt[n-1] > W)
    {
        return KnapsackUsingRec(wt,profit,n-1,W);
    }
}
// This techniques is based on Optimized Recursion. This is Known as Memoizatation techniques..
// It is also known as Top-Down Approach..It takes less time as Recursion approx O(n^2).
// It is also a DP techniques..
int KnapsackOptimized(int wt[], int profit[], int n, int W, int **dp)
{
    //Base condition..
    if(n==0 || W==0)
        return 0;

    if(dp[n][W]!=-1)
        return dp[n][W];
    if(wt[n-1] <= W)
    {
        dp[n][W]=max(profit[n-1] + KnapsackOptimized(wt,profit,n-1,W-wt[n-1],dp), KnapsackOptimized(wt,profit,n-1,W,dp));
        return dp[n][W];
    }
    else if(wt[n-1] > W)
    {
        dp[n][W]=KnapsackOptimized(wt,profit,n-1,W,dp);
        return dp[n][W];
    }
}
// This techniques is known as Tabulation..
// It is Bottom - Up approach..It takes O(n*m) time or O(n^2) when m=n.
// It is pure DP techniques.

int KnapsackUsingDp(int wt[],int P[],int n, int m)
{
    int t[n+1][m+1];    //It is a DP table..
}
main()
{
    int wt[] = {0,2,3,4,5};
    int P[] = {0,1,2,5,6};
    int n = 5;
    int m = 8;
    cout<<"P\twt"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<P[i]<<"\t"<<wt[i]<<endl;
    }
    cout<<"\n";
    int maxProfit = KnapsackUsingRec(wt,P,n,m);
    cout<<"Maximum Profit is: "<<maxProfit<<endl;

    int **dp = new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = new int[m+1];
        //we can use std:: fill_n() to initialize an 1d array.
        fill_n(dp[i],m+1,-1);
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    */
    cout<<"\n";
    maxProfit = KnapsackOptimized(wt,P,n,m,dp);
    cout<<"Maximum Profit is: "<<maxProfit<<endl;

}
