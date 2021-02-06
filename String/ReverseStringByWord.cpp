#include<iostream>
#include<string>     //for string.
#include<stack>
using namespace std;

string reverseByWord(string s)
{
    string temp="";
   //Method:1 - Using stack.
   /*
    stack<char>st;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i]!= ' ')
            st.push(s[i]);
        if(s[i]==' ' || i==0)
        {

            while(!st.empty())
            {
                temp = temp + st.top();
                st.pop();
            }
            temp+=" ";
        }
    }
    */
    //Method:2 - Using string substr() function.
    int j=s.length()-1;
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i]==' ')
        {
            temp = temp + s.substr(i+1,j);
            temp+=" ";
            j=i;
        }
        if(i==0)
        {
            temp = temp + s.substr(i,j);
        }
    }
    return temp;
}
main()
{
    string str;
    cout<<"Enter a line of strings : ";
    //cin>>str;
    getline(cin, str);
    cout<<"The original string is: "<<str<<endl;
    // cout<<str.substr(5)<<endl;
    // cout<<str<<endl;
    cout<<"String After reversing the word is: ";
    string rev = reverseByWord(str);
    cout<<rev<<endl;
}
