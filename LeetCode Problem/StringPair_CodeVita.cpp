#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<string>hm={"zero","one","two","three","four","five","six","seven","eight","nine"};
int countVowel(int x)
{
    string s = hm[x];
    int count=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            count++;
    }
    return count;
}
int countPair(int *arr, int n, int target)  //same as two sum problem.
{
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        count += m[target - arr[i]];
        if(target-arr[i]==arr[i])
            count--;
    }
    return count/2;
}
main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    int digitSum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        digitSum += countVowel(arr[i]);
    }
    int ans = countPair(arr,n,digitSum);
    cout<<hm[ans];
}
