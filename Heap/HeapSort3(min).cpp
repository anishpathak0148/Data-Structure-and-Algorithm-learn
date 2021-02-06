#include<iostream>
using namespace std;
void heapifyMin(int arr[], int n, int root)
{
    int smallest = root;
    int left = 2*root+1;
    int right = 2*root+2;
    if(left<n && arr[left]<arr[smallest])
        smallest = left;
    if(right<n && arr[right]<arr[smallest])
        smallest = right;
    if(smallest != root){
        swap(arr[root],arr[smallest]);

        heapifyMin(arr,n,smallest);
    }
}
//This function build a heap in O(n) time..
int* buildMinHeap(int *arr, int n)
{
    int start_index = n/2-1;
    for(int i=start_index; i>=0;i--)
    {
        heapifyMin(arr,n,i);
    }
    return arr;
}
//this function delete an element in an existing max heap and after deletion it maintain the property of max heap.
//Time complexity to delete an element in an Heap is: O(log n).
void DeletionInMinHeap(int *heap, int n)
{
    swap(heap[0],heap[n-1]);
    n=n-1;  //because we delete an element from heap.
    //now we maintaining the property of Max Heap.
    heapifyMin(heap,n,0);

}
//This function will takes O(n + n*log(n)) = O(n*log(n)) time..
void HeapSortMin(int *arr, int n)
{
    //first we need to build the heap..
    int *heap = buildMinHeap(arr,n);   //this will takes O(n) time..
    //now we need to delete node from heap n-1 time..
    int size=n;
    for(int i=0;i<n-1;i++)
    {
        DeletionInMinHeap(heap,size--); //this will take O(log n) time..
    }
}
void displayHeap(int *heap,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}
main()
{
    //int n=7;
    //int a[n]={10,20,5,8,25,15,40};
    int n;
    cout<<"Enter no of element:";
    cin>>n;
    int *a = new int[n];
    cout<<"Enter element to create Heap:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    HeapSortMin(a,n);
    cout<<"After heap sort array is:"<<endl;
    displayHeap(a,n);
}
