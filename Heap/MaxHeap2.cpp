#include<iostream>
using namespace std;

//this function insert an element in an existing max heap and after insertion it maintain the property of max heap.
//Time complexity to insert an element in an Heap is: O(log n).
int* InsertionInMaxHeap(int *heap, int n, int data)
{
    if(n==10)
    {
        cout<<"Overflow--Heap memory is full.";
        return NULL;
    }
    heap[n]=data;
    if(n>0)
        {
            int j=n;
            int root=(j-1)/2;
            while(root>=0 && heap[root]<heap[j])
            {
                swap(heap[root],heap[j]);
                j=root;
                root=(root-1)/2;
            }
        }
    return heap;
}

void heapifyHelper(int *arr, int n, int root)
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

        heapifyHelper(arr,n,largest);
    }
}
//this function delete an element in an existing max heap and after deletion it maintain the property of max heap.
//Time complexity to delete an element in an Heap is: O(log n).
void DeletionInMaxHeap(int *heap, int n)
{
    int temp=heap[0];   //we always delete root element in heap which is present at index at 0.
    cout<<"\nDeleted Node is:"<<temp<<endl;
    //and at root position we put last leaf element after that we again maintaining the property of MaxHeap.
    swap(heap[0],heap[n-1]);
    n=n-1;  //because we delete an element from heap.
    //now we maintaining the property of Max Heap so call the heapify function.
    heapifyHelper(heap,n,0);

}
void displayHeap(int *heap,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

void drowHeap(int *heap, int n)
{
    cout<<heap[0]<<endl;
    for(int i=1;i<n;i++)
    {

    }
}
main()
{
    //first of all we build an existing MaxHeap.
    int n;
    cout<<"Enter no of element:";
    cin>>n;
    //Here we create a Heap array of 10 elements.So that this Heap does not contain more than 10 elements.
    int *heap = new int[10];
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
    int item;
    cout<<"Enter item to insert in Heap:";
    cin>>item;
    InsertionInMaxHeap(heap,n++,item);
    //n++;
    cout<<"After Insertion Max Heap is:";
    displayHeap(heap,n);
    cout<<"After Deletion Max Heap is:";
    DeletionInMaxHeap(heap,n--);
    displayHeap(heap,n);

}
