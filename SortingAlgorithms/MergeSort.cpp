// Time Complexity: O(n*log2(n))  Space Complexity: O(2*n).
#include<iostream>
using namespace std;
void Merging(int *arr, int l, int mid, int h)
{
    int m = mid-l+1;
    int n = h-mid;
    int *L = new int[m];
    int *R = new int[n];
    for(int i=0;i<m;i++)
    {
        L[i] = arr[l+i];
    }
    for(int j=0;j<n;j++)
    {
        R[j] = arr[mid+1+j];
    }
    //now Merge List L[] and R[].
    int i=0,j=0,k=l;
    while(i<m && j<n)
    {
        if(L[i]<R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    for(;i<m;i++)
        arr[k++] = L[i];
    for(;j<n;j++)
        arr[k++] = R[j];
    //now delete the extra list L[] and R[].
    delete []L;
    delete []R;
}
void MergeSort(int *arr, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,h);
        Merging(arr,l,mid,h);
    }
}
main()
{
    int n;
    cout<<"Enter no of element in Array:";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter elements in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    cout<<"After Sorting list is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
