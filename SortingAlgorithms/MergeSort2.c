#include<iostream>
#define MAX 20
using namespace std;
class mergeSort
{
private:
    int i,a[MAX],b[MAX];
public:
    int n;
    int input()
    {
        cout<<"Enter the size of array : ";
        cin>>n;
        cout<<"Enter array element: ";
        for(i=0;i<n;i++)
            cin>>a[i];
        return n;
    }
    void merge_sort(int lower ,int upper)
    {
        int mid;
        if(lower<upper)
        {
            mid=(lower+upper)/2;
            merge_sort (lower, mid);
            merge_sort (mid+1, upper);
            merging(a, lower, mid, upper);
        }
    }
    void merging(int a[], int p, int q, int r)
    {
        int i, j, k;
        k = 0;
        i = p;
        j = q + 1;
        while (i <= q && j <= r)
        {
            if (a[i] < a[j])
            b[k++] = a[i++];
            else
            b[k++] = a[j++];
        }
        while(i <= q)
        b[k++] = a[i++];
        while(j <= r)
        b[k++] = a[j++];
        for(i = r; i >= p; i--)
        a[i] = b[--k];
    }
    void display()
    {
        for(i=0;i<n;i++)
            cout<<"\t"<<a[i];
    }
};
int main()
{
      cout<<"Merge_Sort....\n";
      mergeSort m;
      m.input();
      cout<<"Before Sorting :"<<endl;
      m.display();
      int len=m.n;
      m.merge_sort(0,len-1);
      cout<<"\nAfter Sorting:"<<endl;
      m.display();
      cout<<"\n\nName:ANISH PATHAK\nUID:17BCS2732"<<endl;
      return 0;
}
