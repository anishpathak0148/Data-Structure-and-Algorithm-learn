#include<iostream>
using namespace std;
void PrintSubseq(string s,string output)
{
    if(s.length()==0){
        cout<<output<<endl;
        return;
    }
    PrintSubseq(s.substr(1),output);
    PrintSubseq(s.substr(1),output+s[0]);

}
main()
{
    string s;
    cout<<"Enter a string:";
    cin>>s;
    cout<<"All Subsequence of string - "<<s<<" is:"<<endl;
    PrintSubseq(s,"");
}
