#include<iostream>
#include<vector>
using namespace std;
// this techniques is based on Dynamic Programming Bottom-Up Approach.
// Time Complexity is: O(n^2) and space complexity: O(n^2).
int MinPathSum_DP(int **arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n,0));    //creating a dp[][] vector and initialize with 0.
    dp[0][0] = arr[0][0];
    // fill first col of each row in dp.
    for(int i=1;i<n;i++)
        dp[i][0] = arr[i][0] + dp[i-1][0];
    // fill first row of each col in dp.
    for(int j=1;j<n;j++)
        dp[0][j] = arr[0][j] + dp[0][j-1];
    //now fill other cell which has two option either from top or left cell.
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = arr[i][j] + min(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n-1][n-1];
}
main()
{
    int n;
    cout<<"Enter no of rows or cols:";
    cin>>n;
    cout<<"Enter Matrix/grid element:"<<endl;
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    cout<<"Minimum Path sum is: "<<MinPathSum_DP(arr,n)<<endl;
}
/*
Test case1:
n=3
1 3 5
2 1 2
4 3 1
Ans = 7
*/
