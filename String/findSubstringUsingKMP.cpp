#include<iostream>
#include<vector>
using namespace std;

int findSubstring(string str, string sub)
{
    int n=str.length();
    int l=sub.length();
    int i,j,k;
    for(i=0;i<=n-l+1;i++)
    {
        k=i;
        for(int j=0;j<l;j++)
        {
            if(str[k]!=sub[j])
            {
                break;
            }
            k++;
        }
        if(j==l)
            return(i);
    }
    return(-1);
}
//Time Complexity: O(n+m).
int KMP_algo(string str, string pattern)
{
    int n=str.length();
    int m=pattern.length();
    //prepare pi table for pattern:
    vector<int>lps(m);  //lps: longest proper prefix which is also suffix.
    int len=0,i;
    lps[0]=0;   //lps[0] is always 0.
    i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len>0)
                len = lps[len-1];
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
    //now traverse the whole string and match the pattern.
    i=0;
    int j=0;
    int index=-1;
    vector<int>v;//for inserting all the index of pattern.
    while(i<n)
    {
        if(str[i]==pattern[j])
        {
            i++;
            j++;
        }
        //else if(i<n && str[i] != pattern[j])
        else
        {
            if(j!=0)
                j = lps[j-1];
            else
                i = i+1;    //if j==0 then we don't move j further. Move i by 1.
        }
        if(j==m)
        {
            index = i-j;
            v.push_back(index);
            cout<<"Pattern match at: "<<index<<" index."<<endl;
            j = lps[j-1];
        }

    }
    return v[0];
}
main()
{
    string s="ababbabaabab";
    string sub = "abb";
    int index;
    //index = findSubstring(s,sub);
    //s = "ABABDABACDABABCABAB";
    //sub = "ABABCABAB";

    s= "AABAACAADAABAABA";
    sub = "AABA";
    index = KMP_algo(s,sub);
    if(index==-1)
        cout<<"Substring not found.";
    else
        cout<<"Substring found at "<<index<<" index.";
}
