#include<iostream>
#include<vector>
using namespace std;

int LIS_result(vector<int>v)
{
    int n=v.size();
    vector<int> LIS(n,1);
    int j=0,i=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<=i-1;j++)
        {
            if(v[j]<v[i] && LIS[i]<LIS[j]+1)
                LIS[i]=LIS[j]+1;
        }
    }
    return LIS[n-1];
}
main()
{
    //vector<int> arr={10,22,9,33,21,50,41,60};
    cout<<"Enter n and Array element:"<<endl;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Given Array is :"<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<"\t"<<arr[i];
    cout<<"\n\nLength of Longest Increasing Subsequence of given array is:"<<LIS_result(arr);
}
/*
Test case1:
8
10 22 9 33 21 50 41 60

Output1: 5

Test case2:
5
2 7 4 3 8

Output2: 3

Test case3:
6
2 4 3 7 4 5

Output3: 4

Time Complexity: O(n2)
*/
