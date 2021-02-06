#include<iostream>
using namespace std;

void permute(char *c, int l, int r)
{
    if(l==r)
        cout<<c<<" ";
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap((c+l),(c+i));
            permute(c,l+1,r);
            swap((c+i),(c+l));  //backtrack.
        }
    }
}
main()
{
    //string s;
    //cout<<"Enter a string to find its permutation: ";
    //cin>>s;
    char *s = "ABC";
    int len=s.length();
    cout<<"Different permutation of string "<<s<<" is:"<<endl;
    permute(s,0,len-1);
}
