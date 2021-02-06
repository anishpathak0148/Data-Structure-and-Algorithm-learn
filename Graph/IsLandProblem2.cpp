/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

 */

#include<iostream>
#include<vector>
using namespace std;

void dfs_markedIsland(vector<int>arr[], int r, int c, int i, int j)
{
    //Boundry case..
    if(i<0 || i>=r || j<0 || j>=c || arr[i][j]!=1)
        return;
    arr[i][j]=2;//marked as 2.

    dfs_markedIsland(arr,r,c,i-1,j);
    dfs_markedIsland(arr,r,c,i,j-1);
    dfs_markedIsland(arr,r,c,i,j+1);
    dfs_markedIsland(arr,r,c,i+1,j);
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
                dfs_markedIsland(A,N,M,i,j);
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
Ans = 3

Test case:2
4 4
1 1 0 0
0 0 1 0
0 0 0 1
0 1 0 0
Ans = 4

*/
