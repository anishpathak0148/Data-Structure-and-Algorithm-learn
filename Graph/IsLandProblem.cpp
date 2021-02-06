/*
Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix.
Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs_markedIsland(vector<int>arr[],int i, int j, int r, int c)
{
    //Boundry case..
    if(i<0 || i>=r || j<0 || j>=c || arr[i][j]!=1)
        return;
    arr[i][j]=2;//marked as 2.
    dfs_markedIsland(arr,i-1,j-1,r,c);
    dfs_markedIsland(arr,i-1,j,r,c);
    dfs_markedIsland(arr,i-1,j+1,r,c);
    dfs_markedIsland(arr,i,j-1,r,c);
    dfs_markedIsland(arr,i,j+1,r,c);
    dfs_markedIsland(arr,i+1,j-1,r,c);
    dfs_markedIsland(arr,i+1,j,r,c);
    dfs_markedIsland(arr,i+1,j+1,r,c);
}
//Time complexity : O(n*m)
int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int no_land = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j]==1)
            {
                dfs_markedIsland(A,i,j,N,M);
                no_land +=1;
            }
        }
    }
    return no_land;
}
main()
{
    int n,m;
    cout<<"Enter no of row and col of Matrix:"<<endl;
    cin>>n>>m;
    vector<int> *arr = new vector<int>[n];
    cout<<"Enter Matrix Elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        vector<int>v(m);
        for(int j=0;j<m;j++)
        {
            cin>>v[j];
        }
        arr[i] = v;
    }
    cout<<"Total no of Island is: "<<findIslands(arr,n,m);
}
/*
Test case:1
3 3
1 1 0
0 0 1
1 0 1
Ans = 2

Test case:2
4 4
1 1 0 0
0 0 1 0
0 0 0 1
0 1 0 0
Ans = 2

*/
