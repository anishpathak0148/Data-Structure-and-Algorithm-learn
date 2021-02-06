#include<iostream>
#include<vector>
using namespace std;

void getWays(int m, vector<int> c) {
int n=c.size();
    int arr[n][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0)
                arr[i][j]=1;
            else if(i==0)
            {
                if(j%c[i]==0)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
            }
            else if(j<c[i])
            {
                arr[i][j]=arr[i-1][j];
            }
            else if(j>=c[i])
            {
                arr[i][j]= arr[i-1][j] + arr[i][j-c[i]];
            }
        }
    }
    cout<<"Total no of ways to get change is: "<<arr[n-1][m]<<endl;
    cout<<"\nTable to get total no of ways:- "<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<"\t"<<arr[i][j];
        cout<<endl;
    }
}
void MinimumCoin(int m,vector<int>c)
{
    int n=c.size();
    int arr[n][m+1];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j==0)
                arr[i][j]=0;
            else if(i==0)
            {
                if(j%c[i]==0)
                    arr[i][j]=j/c[i];
                else
                    arr[i][j]=0;
            }
            else if(j<c[i])
                arr[i][j]=arr[i-1][j];
            else if(j>=c[i])
            {
                arr[i][j] = min(arr[i-1][j], 1+arr[i][j-c[i]]);
            }
        }
    }
    cout<<"\n\nMinimum no of coins to get the change is: "<<arr[n-1][m]<<endl;
    cout<<"\nTable for minimum no of coins is:-"<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
            cout<<"\t"<<arr[i][j];
        cout<<endl;
    }
}
main()
{
    /*
    vector <int> coin={1,5,6,8};
    int amount=11;

    vector<int> coin = {3,5};
    int amount=7;
    */
    int n,amount;
    cout<<"Enter no of coins available for change: ";
    cin>>n;
    vector<int>coin(n);
    cout<<"Enter coins to make the change of entire amount: ";
    for(int i=0;i<n;i++)
        cin>>coin[i];
    cout<<"Enter Amount to change: ";
    cin>>amount;
    getWays(amount,coin);
    MinimumCoin(amount,coin);
}


