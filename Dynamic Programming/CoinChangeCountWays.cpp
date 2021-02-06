#include<iostream>
using namespace std;
int countWays(int *d, int k, int n, int **dp)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    if(k==0)
        return 0;
    if(dp[n][k]>=0)
        return dp[n][k];
    int opt1 = countWays(d,k,n-d[0],dp);
    int opt2 = countWays(d+1,k-1,n,dp);
    dp[n][k]=opt1 + opt2;
    cout<<"DP Table is:"<<endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    return dp[n][k];
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    /*
    sort(denominations, denominations+numDenominations);
    int dp[numDenominations][value+1];
    for(int i=0;i<numDenominations; i++)
    {
        dp[i][0]=1;
        for(int j=1;j<=value;j++)
        {
            if(i==0)
            {
                if(j%denominations[i]==0)
                    dp[i][j]=1;
                else
                    dp[i][j]=0;
            }
            else
            {
                if(denominations[i]<j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-denominations[i]];
                }
            }
        }
    }
return dp[numDenominations-1][value];
*/

    int **dp = new int*[value+1];
    for(int i=0;i<=value;i++)
    {
        dp[i] = new int[numDenominations];
        for(int j=0;j<numDenominations;j++)
            dp[i][j] = -1;
    }
    return countWays(denominations,numDenominations,value,dp);
}
main()
{
    cout<<"Enter input n, w and array:"<<endl;
    int n,w;
    cin>>n>>w;
    int *c = new int[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    cout<<"\nTotal Ways is: "<<countWaysToMakeChange(c,n,w);
}
