#include<iostream>
#include<vector>
using namespace std;
int result(char* s)
{
    //int n=s.length();
    int n=0,i=0;
    while(s[i++]!='\0')
        n++;
    vector<int>lis(n,1);
    int j;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(s[j]<s[i] && lis[i]<lis[j]+1)
                lis[i] = lis[j]+1;
        }
    }
    return lis[n-1];
}
main()
{
    string s;
    //cout<<"Enter string:"<<endl;
    //cin>>s;
    char *str = "bcdabdz";
    cout<<"Result: "<<result(str);
}
