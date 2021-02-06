#include<iostream>
#include<queue>
using namespace std;
int OptimalMerge(int n, int *file)
{
    //first of all we sort the file according to size.
    //create a priority queue and implement MinHeap.
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<n;i++)
    {
        pq.push(file[i]);
    }
    int count=0;
    while(pq.size()>1)
    {
        int left = pq.top();
        pq.pop();
        int right = pq.top();
        pq.pop();
        //now merge this file left and right and push back in MinHeap or priority queue;
        pq.push(left+right);
        count+= left+right;
    }
    return count;
}
main()
{
    int n;
    cout<<"Enter no of files that you want to Merge: ";
    cin>>n;
    int *file = new int[n];
    cout<<"Enter size of files: ";
    for(int i=0;i<n;i++)
        cin>>file[i];

    int cost = OptimalMerge(n,file);
    cout<<"Total cost to merge these file is: "<<cost;

}
/*
Test case1:
n = 6
files = [4 5 2 3 7 6]
Output:
cost=68

Test case2:
n=5
files = [20 30 10 5 30]
Output:
cost = 205
*/
