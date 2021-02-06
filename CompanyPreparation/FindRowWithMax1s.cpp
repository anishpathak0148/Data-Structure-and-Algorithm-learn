#include<iostream>
#define r 4
#define c 5
using namespace std;
int Search(bool a[], int l, int h)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if((mid==0 || a[mid-1]==0) && a[mid]==1)
            return mid;
        else if(a[mid]==0)
            return Search(a,mid+1,h);
        else
            return Search(a,l,mid-1);
    }
    return -1;
}
int rowInd(bool arr[][c])
{
    int max_row=0,max=-1;
    int i,index;
    for(i=0;i<r;i++)
    {
        index = Search(arr[i],0,c-1);
        if(index!=-1 && c-index > max)
        {
            max = c-index;
            max_row = i;
        }
    }
    return max_row;
}
main()
{
    bool arr[][c]={{0,0,0,1,1},{0,0,1,1,1},{0,1,1,1,1},{1,1,1,1,1}};
    int i = rowInd(arr);
    cout<<"Maximum no of 1s in row of index: "<<i<<endl;
}
