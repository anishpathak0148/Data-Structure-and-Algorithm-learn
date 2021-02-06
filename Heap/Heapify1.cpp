#include<iostream>
using namespace std;
void heapify(int *arr, int n, int root)
{
    int largest = root;
    int left = 2*root+1;
    int right = 2*root+2;
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    if(largest != root){
        swap(arr[root],arr[largest]);

        heapify(arr,n,largest);
    }
}
int* buildHeap(int *arr, int n)
{
    int start_index = n/2-1;
    for(int i=start_index; i>=0;i--)
    {
        heapify(arr,n,i);
    }
    return arr;
}
main()
{
    //int n=7;
    //int a[n]={10,20,5,8,25,15,40};
    int n;
    cout<<"Enter no of element:";
    cin>>n;
    int a[n];
    cout<<"Enter element to create Heap:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int *heap = buildHeap(a,n);
    cout<<"Max Heap is: ";
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<"\t";
    }
}
