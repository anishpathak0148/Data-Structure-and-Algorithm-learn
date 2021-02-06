#include<iostream>
#include<vector>
using namespace std;
//Approach1: Using a HashMap.
//Time complexity: O(n).  Space complexity: O(n).
int missingNum1(int *arr, int n)
{
    //create a hashMap..
    vector<int>hm(n+1,false);
    for(int i=0;i<n-1;i++)
    {
        hm[arr[i]]=true;
    }
    //now traverse the hashMap..
    for(int i=1;i<hm.size();i++)
    {
        if(hm[i]==false)
            return i;
    }
}
//second Approach: Using Sum method..But in this approach integer overflow may come.
//Time complexity: O(n). Space complexity: O(1).
int missingNum2(int *arr, int n)
{
    //sum of 1st n natural number..
    int sum = n*(n+1)/2;
    int total=0;
    for(int i=0;i<n-1;i++)
    {
        total += arr[i];
    }
    //missing number is: sum-total.
    return sum-total;
}
//Approach3: Using XOR method..
//Time complexity: O(n). Space complexity: O(1).
int missingNum3(int *arr, int n)
{
    int xorTotal,xorArr;
    //find XOR on all Array element..
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
            xorArr = arr[i];
        else
            xorArr ^= arr[i];
    }
    //now find XOR on total n element..
    for(int i=1;i<=n;i++)
    {
        if(i==1)
            xorTotal = 1;
        else
            xorTotal ^=i;
    }
    //Missing number is: xorTotal ^ xorArr.
    return xorTotal ^ xorArr;
}
main()
{
    int n;
    cout<<"Enter a number n:";
    cin>>n;
    int *arr = new int[n-1];
    cout<<"Enter n-1 element in array:"<<endl;
    for(int i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    cout<<"Missing Number is: "<<missingNum1(arr,n)<<endl;
    cout<<"Missing Number is: "<<missingNum2(arr,n)<<endl;
    cout<<"Missing Number is: "<<missingNum3(arr,n)<<endl;
}
