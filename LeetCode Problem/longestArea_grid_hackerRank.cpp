#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    vector<int>res={0};
    for(int i=0;i<n-1;i++)
    {
        int count=0;
        for(int j=i;j<n-1;j++)
        {
            if(arr[i][j]==1 && arr[i][j+1]==1 && arr[i+1][j]==1 && arr[i+1][j+1]==1)
                count++;
            else
            {
                res.push_back(count+1);
            }
        }
    }
    int ans = *max_element(res.begin(),res.end());
    cout<<"Ans is:"<<ans;
}
