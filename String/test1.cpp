#include<iostream>
using namespace std;
main()
{
    int arr[] = {1,2,5,0,3,10,25,60,5,-10};
    int n=11;
    int first=arr[0];
    int second=-99999;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<first)
        {
            second = first;
            first = arr[i];

        }
        else if(arr[i]>first && arr[i]<second)
        {
            second = arr[i];
        }
    }
    cout<<"First Smallest is: "<<first<<endl;
    cout<<"Second smallest is: "<<second<<endl;
}
