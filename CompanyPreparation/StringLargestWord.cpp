#include <iostream>

using namespace std;

int main()
{
    string str;
    //cin>>str; // Iske sath problem ye hai ki jab bhi koi whitespace hum input lete hai to ye uske baad ke text ko consider nhi karta hai.
    getline(std::cin, str);
    cout<<"Size of string is: "<<str.size()<<endl;
    int ct=0,ct1=0;
    string s1="",s2="";
    for(char c : str)
    {
        if(c>32 && c<=47)
        {
            continue;
        }
        if(c==' ' && ct<ct1)
        {
            s1=s2;
            s2="";
            ct=ct1;
            ct1=0;
        }
        else{
            ct1++;
            s2 = s2+c;
        }

    }
    if(ct<ct1)
    {
        s1=s2;
        ct=ct1;
    }
    cout<<"Ans is: "<<s1<<endl;
    return 0;
}

