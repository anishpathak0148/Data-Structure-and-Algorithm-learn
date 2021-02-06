#include<iostream>
#define mod 1000000007
using namespace std;
int dtob(int n)
{

    string x="";
    for(int i=1;i<=n;i++)
    {
        string binary="";
        int decimal=i;
        while(decimal!=0)
        {
            binary = to_string(decimal%2) + binary;
            decimal /= 2;
        }
        x = x+binary;
    }
    //return binary;
    string num = x;
    int dec_value = 0;
    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1'){
            dec_value += base;
            dec_value = dec_value%mod;
        }
        base = base * 2;
    }

    return dec_value;
}
main()
{
    int n=3;
    cout<<dtob(n);
}
