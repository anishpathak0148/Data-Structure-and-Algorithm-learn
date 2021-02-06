#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Edges
{
public:
    int src;
    int dest;
    int weight;
};
bool compare(Edges e1, Edges e2)
{
    return e1.weight<e2.weight;
}

int findParent(int v, int *parent)
{
    if(parent[v]==v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void KruskalMST(Edges *input,int n, int E)
{
    //sort the given array according to their weight.
    sort(input, input+E, compare);
    Edges *output = new Edges[n-1];

    int *parent = new int[n];
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!=n-1)
    {
        Edges currEdge = input[i];
        //check whether we can add currEdge in MST or not:
        int srcParent = findParent(currEdge.src, parent);
        int destParent = findParent(currEdge.dest, parent);

        if(srcParent!=destParent)
        {
            output[count]=currEdge;
            count++;
            parent[srcParent]=destParent;
        }
        i++;
    }
    //now print the output mst list.
    for(int i=0;i<n-1;i++)
    {
        cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }
}
main()
{
    int n,E;
    cout<<"Enter no of Vertices and edges:";
    cin>>n>>E;
    Edges *input = new Edges[E];
    cout<<"Enter Source Destination and Weight of the edge:"<<endl;
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].src=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    cout<<"Minimum Spanning tree of given graph is:"<<endl;
    KruskalMST(input,n,E);
}
/*
Test case:1
6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8
4 5 2
2 5 9
3 5 6
*/
