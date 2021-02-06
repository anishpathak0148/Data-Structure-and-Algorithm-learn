#include<iostream>
using namespace std;

bool PalindromeHelper(string str, int s, int  e)
{
    if(s==e)
        return true;
    if(str[s]!=str[e])
        return false;
    PalindromeHelper(str,s+1,e-1);
    return true;
}
bool isPalindrome(string s)
{
    int n=s.length();
    if(PalindromeHelper(s,0,n-1))
        return true;
    else
        return false;
}
main()
{
    string str;
    cout<<"Enter a string to check it is Palindrome or not: ";
    cin>>str;
    cout<<str<<" is Palindrome: "<<isPalindrome(str);
}
