#include<bits/stdc++.h>
using namespace std;

bool isPositionSafe(int chess[10][10], int i, int j, int n)
{
    //we can check it for col.
    for(int row=0;row<i;row++)
    {
        if(chess[row][j]==1)
        {
            return false;
        }
    }
    // we can check it for right diagonal.
    int x=i;
    int y=j;
    while(x>=0 && y<n)
    {
        if(chess[x][y]==1)
            return false;
        x--;
        y++;
    }
    // we can check it for left diagonal.
    x=i;
    y=j;
    while(x>=0 && y>=0)
    {
        if(chess[x][y]==1)
            return false;
        x--;
        y--;
    }
    // now this position is safe in col and diagonals.
    return true;
}
bool NQueenProblem(int chess[10][10],int i, int n)
{
    //Base condition:
    if(i==n)
    {
        // we have successfully placed the Queen in n row (0 to n-1).
        //print the solution.
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(chess[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        //here if we return true then we got only one solution but if we return false then we got all the solutions.
        return false;
    }
    //Recursive case..
    //try to placed the Queen in current row and call on the remaining part which will be solved by Recursion.
    for(int j=0;j<n;j++)
    {
        //I have to check this i,j position is safe or not!
        if(isPositionSafe(chess,i,j,n))
        {
            //placed the Queen. Assuming i,j is right position.
            chess[i][j]=1;
            bool isNextQueen = NQueenProblem(chess,i+1,n);
            if(isNextQueen)
                return true;

            //it means i,j is not right position.Assumption is wrong.
            chess[i][j]=0; //backtrack.

        }
    }
    return false;
}
main()
{
    int chess[10][10]={0};
    int n;
    cout<<"Enter n for dimension of Chess Board:";
    cin>>n;
    NQueenProblem(chess,0,n);
}
