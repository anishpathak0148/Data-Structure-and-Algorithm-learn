#include<iostream>
using namespace std;

bool isPalindrome(string s)
{
    int n=s.length();
    int j=n-1;
    bool flag=true;
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[j])
        {
            flag=false;
            break;
        }
        j--;
    }
    return flag;
}
main()
{
    string str;
    cout<<"Enter a string to check it is Palindrome or not: ";
    cin>>str;
    cout<<str<<" is Palindrome: "<<isPalindrome(str);
}

