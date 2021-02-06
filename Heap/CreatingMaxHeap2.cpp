#include<iostream>
using namespace std;
main()
{
    //int n=7;
    //int a[n]={10,20,5,8,25,15,40};
    int n;
    cout<<"Enter no of element:";
    cin>>n;
    cout<<"Enter element to create Heap:";
    int *heap = new int[n];
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
    cout<<"Max Heap is: ";
    for(int i=0;i<n;i++)
    {
        cout<<heap[i]<<"\t";
    }
}

