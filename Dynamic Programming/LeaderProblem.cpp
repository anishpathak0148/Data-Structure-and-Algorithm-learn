#include<iostream>
using namespace std;
//Using Recursion... It takes O(k^n) times.
int totalWaysRec(int n, int k)
{
    //Base case..
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    int ways=0;
    for(int i=1;i<=k;i++)
        ways += totalWaysRec(n-i,k);
    return ways;
}
// Top down Approach..Memoization techniques..
int totalWaysTopDown(int n, int k, int *dp)
{
    if(dp[n]!=-1)
        return dp[n];
    else
    {
        if(n==0)
            dp[n]=1;
        else
        {
            dp[n] = 0;
            for(int i=1;i<=k;i++)
            {
                if(n-i>=0)
                {
                    dp[n] += totalWaysTopDown(n-i,k,dp);
                }
            }
        }
    }
    return dp[n];
}
//Bottom Up Approach..Using Dynamic Programming techniques...It takes O(k*n) time where k is constant.
int totalWaysDp(int n, int k)
{
    int *dp = new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

//Bottom Up Approach..Using Dynamic Programming techniques...It takes O(n) times.
int totalWaysDpOptimized(int n, int k)
{
    int *dp = new int[n+1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i-k>=0)
            dp[i] = 2*dp[i-1] + dp[i-k];
        else
            dp[i] = dp[i-1];
    }
    return dp[n];
}
main()
{
    int n,k;
    cout<<"Enter size of leader and maximum jump in one step:";
    cin>>n>>k;
    int *t = new int[n+1];
    fill_n(t,n+1,-1);
    cout<<"Total no of ways is Using Top-Down Approach: "<<totalWaysTopDown(n,k,t)<<endl;
    cout<<"Total no of ways is Using DP: "<<totalWaysDp(n,k)<<endl;
    cout<<"Total no of ways is Using DP Optimized: "<<totalWaysDpOptimized(n,k)<<endl;
    cout<<"Total no of ways is Using Recursion: "<<totalWaysRec(n,k)<<endl;
}
