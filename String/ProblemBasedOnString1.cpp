#include<iostream>
#include<map>
using namespace std;

int result(string s)
{
    int n=s.length();
    map<char,int>m;
    int i=1;
    for(char c='A';c<='Z';c++)
    {

        m[c]=i++;
    }
    int temp=0;
    int j=1;

    for(int i=0;i<n;i++)
    {
        int diff=abs(m[s[i]]-j);
        if(diff<=13)
        {
            temp+=diff;
        }
        else if(diff>13)
        {
            diff=26-diff;
            temp+=diff;
        }
        j=m[s[i]];
    }
    return temp;
}
main()
{
    int i=10;
    const int &j=i;
    i=20;
    cout<<i<<" "<<j;
    string s;
    cout<<"Enter a string in Capital letter:";
    cin>>s;
    //char c=90;
    //cout<<c;
    int ans=result(s);
    cout<<"Ans:"<<ans;
}
