#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cin>>n;
	string s1,s2;
	cin>>s1>>s2;
	int c1=0,c2=0;
    for(int i=0;i<n;i++)
	{
        if(s2[i]=='m')
            c1++;
	   else if(s2[i]=='r')
            c2++;
	}
	int a5=0;
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='r')
		{
			if(c2==0)
			{
				break;
			}
			else
			{
				c2--;
				a5++;
			}
		}
		else if(s1[i]=='m')
		{
			if(c1==0)
			{
				break;
			}
			else
			{
				c1--;
				a5++;
			}
		}
	}
		cout<<n-a5<<"\n";
		return 0;
}
