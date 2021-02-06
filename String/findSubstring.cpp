#include<iostream>
using namespace std;

int findSubstring(string str, string sub)
{
    int n=str.length();
    int l=sub.length();
    int i,j,k;
    for(i=0;i<=n-l+1;i++)
    {
        k=i;
        for(j=0;j<l;j++)
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
main()
{
    string s="ababbabaabab";
    string sub = "abaab";
    int index = findSubstring(s,sub);
    if(index==-1)
        cout<<"Substring not found.";
    else
        cout<<"Substring found at index "<<index;
}
