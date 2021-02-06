#include<bits/stdc++.h>
using namespace std;
long long Modulo(long long a, long long b,int m)
{
    long long res = 0;
    a %=m;
    while(b)
    {
        if(b&1)
            res = (res+a)%m;
        a = (2*a)%m;
        b >>=1;
    }
    return res;
}
int main(){
    // write your code
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a>=b)
        {
            cout<<0<<endl;
        }
        else
        {
            long long fact=1;
            if(a%2==0)
            {
                int i=1,j=2;
                while(j<=a)
                {
                    long long temp = Modulo(i,j,b);
                    cout<<temp<<"\t";
                    fact = Modulo(fact,temp,b);
                    cout<<fact<<endl;
                    i +=2;
                    j +=2;
                }
                //long long temp = Modulo(a,a-1,b);
            }
            else
            {
                for(int i=1,j=2;j<a;i+=2,j+=2)
                {
                    long long temp = Modulo(i,j,b);
                    cout<<temp<<"\t";
                    fact = Modulo(fact,temp,b);
                    cout<<fact<<endl;
                }
                fact = Modulo(fact,a,b);
            }
            cout<<fact<<endl;
        }
    }
    return 0;
}
