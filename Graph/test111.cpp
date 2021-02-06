#include<iostream>
using namespace std;
int main()
{
    int i=16;
    for(;i; i>>=1)
    {
        if(i==5)
        {
            cout<<" world ";
            break;
        }
        cout<<i<<" ";
    }
}
