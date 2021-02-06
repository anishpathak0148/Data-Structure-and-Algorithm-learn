#include<iostream>
#include<set>
using namespace std;
//Time Complexity: O(n^2*b). Space complexity(O(n^2)).
void uniqueSubstring(string s)
{
    int n=s.length();
    int ct=0;
    set<string>st;
    for(int i=0;i<n;i++)
    {
        for(int len=1;len<=n-i;len++)
        {
            string str=s.substr(i,len);//It takes linear time:O(b).
            if(st.find(str)==st.end()){
                st.insert(str);
                cout<<str<<endl;
                ct++;
            }
        }
    }
    st.clear();
    cout<<"Total Possible Unique Substrings are: "<<ct<<endl;
}
//Time Complexity: O(n^2). Space complexity(O(n^2)).
void uniqueSubstringOptmz(string s)
{
    int n=s.length();
    int ct=0;
    set<string>st;
    for(int i=0;i<n;i++)
    {
        string ss="";
        for(int j=i;j<n;j++)
        {
            ss += s[j];     //It takes constant time:O(1).
            if(st.find(ss)==st.end()){
                st.insert(ss);
                cout<<ss<<endl;
                ct++;
            }
        }
    }
    st.clear();
    cout<<"Total Possible Unique Substrings are: "<<ct<<endl;
}
main()
{
    string s;
    cout<<"Enter a string:";
    cin>>s;
    cout<<"All Possible Unique substring is:"<<endl;
    uniqueSubstring(s);
    cout<<endl<<endl;
    cout<<"All Possible Unique substring is:"<<endl;
    uniqueSubstringOptmz(s);
}
