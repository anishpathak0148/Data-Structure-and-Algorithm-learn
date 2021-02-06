#include<iostream>
using namespace std;
main()
{
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int x;
    cin>>x;
    int r=-1,c=-1,s,z=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==x)
            {
                r=i;
                c=j;
                break;
            }
        }
        if(r>=0 && c>=0)
        {
            break;
        }
    }
    s = r+c;
    int t=c-s%n;
    if(t>=0)
    {
        z = arr[r][t];
    }
    int sum=0;
    while(z>0)
    {
        int rmd = z%10;
        sum += rmd*rmd;
        z = z/10;
    }
    cout<<"Output:"<<sum;
}
