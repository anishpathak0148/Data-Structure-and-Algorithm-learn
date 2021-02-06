#include<iostream>
using namespace std;
//Time Complexity: O(n^2*k). Space complexity(O(1)).
void AllSubString(string str)
{
    int n=str.length();
    int ct=0;
    for(int i=0;i<n;i++)
    {
        for(int len=1;len<=n-i;len++)
        {
            cout<<str.substr(i,len)<<endl;//It takes linear time:O(k).
            ct++;
        }
    }
    cout<<"Total Possible Substrings are: "<<ct<<endl;
}
//Time Complexity: O(n^2). Space complexity(O(1)).
void AllSubStringOptmz(string str)
{
    int n=str.length();
    int ct=0;
    for(int i=0;i<n;i++)
    {
        string ss="";
        for(int j=i;j<n;j++)
        {
            ss += str[j];//It takes constant time.O(1).
            cout<<ss<<endl;
            ct++;
        }
    }
    cout<<"Total Possible Substrings are: "<<ct<<endl;
}
main()
{
    string s;
    cout<<"Enter a string:";
    cin>>s;
    cout<<"All Possible substring is:"<<endl;
    AllSubString(s);
    cout<<endl<<endl;
    cout<<"All Possible substring is:"<<endl;
    AllSubStringOptmz(s);
}
