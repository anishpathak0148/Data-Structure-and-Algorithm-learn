#include<iostream>
using namespace std;
//Approach: Dynamic Programming approach..
//Time complexity: O(n^2). Space complexity: O(n^2).
string longestPalindromicSubstring(string s)
{
    int n= s.length();
    int dp[n][n];
    //first fill table for length 2.
    for(int i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;i++)
    {
        dp[i][i+1] = (s[i]==s[i+1])? 1:0;
    }
    //now fill table for length>=3.
    int k=2;    //k = len-1;
    while(k<n)
    {
        for(int i=0;i<n-k;i++)
        {
            int l=i,r=i+k;
            if(s[l]==s[r] && dp[l+1][r-1]==1)
                dp[l][r]=1;
            else
                dp[l][r]=0;
        }
        k++;
    }
    //now scan dp[][] array and find max length of palindromic substring.
    int max_len = 0;
    string res="";
    for(int i=0;i<n;i++)
    {
        int l=i,r=n-1;
        while(dp[i][l]!=1)
            l++;
        while(dp[i][r]!=1)
            r--;
        //length = r-l+1.
        int len = r-l+1;
        if(max_len < len)
        {
            max_len = len;
            res = s.substr(l,len);
        }
    }
    cout<<"Maximum length of Palindromic Substring is: "<<max_len<<endl;
    return res;
}
int main()
{
    cout<<"Enter string:"<<endl;
    string str;
    cin>>str;
    string result = longestPalindromicSubstring(str);
    cout<<"Longest palindromic substring is: "<<result<<endl;
}
