#include<iostream>
using namespace std;
void rotateArray(int *arr,int n, int k)
{
    int t = k%n;
    while(t--){
    int temp=arr[0];
    for(int i=0;i<n;i++)
    {
        int temp1=arr[(i+1)%n];
        arr[(i+1)%n] = temp;
        temp=temp1;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    }
}
main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    cout<<"Result is:"<<endl;
    int k=10;
    rotateArray(arr,n,k);

}
