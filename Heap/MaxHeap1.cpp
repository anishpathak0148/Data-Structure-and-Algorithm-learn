#include<iostream>
using namespace std;
void Build_MaxHeap(int heap[],int i)
{
    int j=2*i;
    int n=heap[0];
    int flag=0;
    while(j<=n && flag==0)
    {
        if(j+1<n && heap[j]<heap[j+1])
        {
            j=j+1;
        }
        if(heap[i]<heap[j])
        {
            int temp=heap[i];
            heap[i]=heap[j];
            heap[j]=temp;
        }
        else
            flag=1;
    }
}
main()
{
    int arr[20],n;
    cout<<"Enter the no of elements:";
    cin>>n;
    arr[0]=n;
    cout<<"Enter the "<<n<<" elements in heap:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    //element down adjust in max heap;
    for(int i=n/2;i>=1;i--)
    {
        Build_MaxHeap(arr,i);
    }
    //now show the element of heap.
    cout<<"\nElement in Max heap is:"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
