#include<iostream>
using namespace std;
void heapify(int arr[], int n, int root)
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
//this function delete an element in an existing max heap and after deletion it maintain the property of max heap.
//Time complexity to delete an element in an Heap is: O(log n).
void DeletionInMaxHeap(int *heap, int n)
{
    int temp=heap[0];   //we always delete root element in heap which is present at index at 0.
    //and at root position we put last leaf element after that we again maintaining the property of MaxHeap.
    swap(heap[0],heap[n-1]);
    n=n-1;  //because we delete an element from heap.
    //now we maintaining the property of Max Heap.
    heapify(heap,n,0);

}
void displayHeap(int *heap,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}
void HeapSort(int *heap, int n)
{
    int size=n;
    for(int i=0;i<n-1;i++)
    {
        DeletionInMaxHeap(heap,size--);
    }
}
main()
{
    //first of all we build an existing MaxHeap.
    int n;
    cout<<"Enter no of element:";
    cin>>n;
    //Here we create a Heap array of 10 elements.So that this Heap does not contain more than 10 elements.
    int *heap = new int[n];
    cout<<"Enter element to create Heap:";
    for(int i=0;i<n;i++)
    {
        cin>>heap[i];
        if(i>0)
        {
            int j=i;
            int root=(j-1)/2;
            while(root>=0 && heap[root]<heap[j])
            {
                swap(heap[root],heap[j]);
                j=root;
                root=(root-1)/2;
            }
        }
    }
    cout<<"Existing Max Heap is: ";
    displayHeap(heap,n);
    //Sort the heap using heap Sort..
    HeapSort(heap,n);
    cout<<"After Heap Sort the array is:"<<endl;
    displayHeap(heap,n);
}

