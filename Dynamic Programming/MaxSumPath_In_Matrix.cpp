#include<iostream>
#include<vector>
using namespace std;
int PathSumHelper(int **arr, int **dp, bool **visited, int n, int i, int j)
{
    if(i==n-1 && j==n-1)
        return arr[i][j];
    if(visited[i][j])
        return dp[i][j];
    visited[i][j] = true;
    int total = 0;
    if(i<n-1 && j<n-1)
    {
        int curr_sum = max(PathSumHelper(arr,dp,visited,n,i,j+1), PathSumHelper(arr,dp,visited,n,i+1,j));
        total = arr[i][j] + curr_sum;
    }
    else if(i==n-1)
    {
        total = arr[i][j] + PathSumHelper(arr,dp,visited,n,i,j+1);
    }
    else
    {
        total = arr[i][j] + PathSumHelper(arr,dp,visited,n,i+1,j);
    }
    dp[i][j] = total;
    return total;
}
int MaxPathSum(int **arr, int n)
{
    int **dp = new int*[n];
    bool **visited = new bool*[n];
    for(int i=0;i<n;i++)
    {
        dp[i] = new int[n];
        visited[i] = new bool[n];
        for(int j=0;j<n;j++)
        {
            dp[i][j]=0;
            visited[i][j]=false;
        }
    }
    return PathSumHelper(arr,dp,visited,n,0,0);
}

// this techniques is based on Dynamic Programming Bottom-Up Approach.
// Time Complexity is: O(n^2) and space complexity: O(n^2).
int MaxPathSum_Dp(int **arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n,0));
    dp[0][0] = arr[0][0];
    //fill first col of each row in dp table.
    for(int i=1;i<n;i++)
        dp[i][0] = arr[i][0] + dp[i-1][0];
    //fill first row of each col in dp table.
    for(int j=1;j<n;j++)
        dp[0][j] = arr[0][j] + dp[0][j-1];
    //fill another cell which has two option either from top or left.
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][n-1];
}
main()
{
    int n;
    cout<<"Enter no of row or column:";
    cin>>n;
    cout<<"Enter Matrix"<<endl;
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Maximum Path Sum is: "<<MaxPathSum(arr,n)<<endl;
    cout<<"Maximum Path Sum is: "<<MaxPathSum_Dp(arr,n)<<endl;
}
/*
Test case1:
n = 5
3 1 -2 1 1
-6 -1 4 -1 -4
1 1 1 1 1
2 2 2 2 2
1 1 1 1 1
Ans = 15

Test case2:
n = 3
1 1 1
2 2 2
3 3 3
Ans = 12

*/
