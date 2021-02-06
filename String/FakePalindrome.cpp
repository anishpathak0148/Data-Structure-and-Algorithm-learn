#include<iostream>
using namespace std;
//Approach: Dynamic Programming approach..
//Time complexity: O(n^2). Space complexity: O(n^2).
int LPS(string s)
{
    int n= s.length();
    int dp[n][n];
    //first fill table for length 2.
    int ct=0;
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
        ct++;
    }
    for(int i=0;i<n-1;i++)
    {
        //dp[i][i+1] = (s[i]==s[i+1])? 1:0;
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            ct++;
        }
        else
            dp[i][i+1]=0;
    }
    //now fill table for length>=3.
    int k=2;    //k = len-1;
    while(k<n)
    {
        for(int i=0;i<n-k;i++)
        {
            int l=i,r=i+k;
            if(s[l]==s[r] && dp[l+1][r-1]==1){
                dp[l][r]=1;
                ct++;
            }
            else
                dp[l][r]=0;
        }
        k++;
    }
    return ct;
}
int main()
{
    cout<<"Enter string:"<<endl;
    string str;
    cin>>str;
    int result = LPS(str);
    cout<<"No of fake Palindrome is: "<<result<<endl;
}

