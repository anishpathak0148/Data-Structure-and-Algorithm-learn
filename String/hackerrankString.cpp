#include<bits/stdc++.h>
using namespace std;
bool isVowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
string findSubstring(string s, int k) {
    map<int,string> hm;
    int start=0;
    int n=s.length();
    for(int i=0;i<n-k+1;i++)
    {
        string str = s.substr(i,k);
        int count=0;
        for(int j=0;j<k;j++)
        {
            if(isVowel(str[i])==true){
                count++;
            }
        }
        if(count>0)
            hm.insert(make_pair(count,str));
    }
    auto it = hm.end();
    it--;
    return it->second;
}
main()
{
    string s;
    int k;
    cout<<"Enter string and k:";
    cin>>s>>k;
    cout<<"Result is: "<<findSubstring(s,k);
}
