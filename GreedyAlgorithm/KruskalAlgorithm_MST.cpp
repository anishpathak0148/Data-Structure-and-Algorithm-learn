#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
    int src;
    int dest;
    int weight;
};

int findParent(int parent[],int v)
{
    if(parent[v]<0)
        return v;
    return findParent(parent, parent[v]);
}
int* unionSet(int parent[], int x, int y)
{
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    /*Here Rank of both set.
        xRank = abs(parent[xSet])
        yRank = abs(parent[ySet])
    */
    int xRank = abs(parent[xSet]);
    int yRank = abs(parent[ySet]);
    // if rank is same.
    if(xRank == yRank){
        parent[xSet] += parent[ySet];
        parent[ySet] = xSet;
    }
    //if rank is different.
    if(xRank > yRank)
    {
        parent[xSet] += parent[ySet];
        parent[ySet] = xSet;
    }
    else if(xRank<yRank)
    {
        parent[ySet] += parent[xSet];
        parent[xSet] = ySet;
    }

    return parent;
}

bool compare(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}
Edge* Kruskal_Mst(Edge *input, int n, int e)
{
    //first of all we need to sort the Edge array.
    sort(input, input+e, compare);
    //now we create an output array of Edge type which is MST.
    Edge *output = new Edge[n-1];
    //creating a Parent array of int type which contain the parent of vertex.
    int *Parent = new int[n];
    for(int i=0;i<n;i++)
    {
        Parent[i]=-1;
    }
    int count=0;
    int i=0;
    while(count!=n-1){
        Edge currEdge = input[i];
        //check whether we can add currEdge in MST or not:
        int srcParent = findParent(Parent, currEdge.src);

        int destParent = findParent(Parent, currEdge.dest);

        if(srcParent==destParent)
        {
            //cycle is found.
            i++;
            continue;
        }
        else
        {
            output[count]=currEdge;
            count++;
            Parent = unionSet(Parent,srcParent,destParent);
        }
        i++;
    }
    return output;
}
main()
{
    int n,e;
    cout<<"Enter no of vertex and edge: ";
    cin>>n>>e;
    Edge *input = new Edge[e];
    for(int i=0;i<e;i++)
    {
        cin>>input[i].src>>input[i].dest>>input[i].weight;
    }
    cout<<"MST is finding"<<endl;
    Edge *mst = new Edge[n-1];
    mst = Kruskal_Mst(input,n,e);
    cout<<"Minimum Spanning Tree is:"<<endl;
    int cost=0;
    cout<<"Src\tDest\tWeight"<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<mst[i].src<<"\t"<<mst[i].dest<<"\t"<<mst[i].weight<<endl;
        cost += mst[i].weight;
    }
    cout<<"\nTotal cost of MST is: "<<cost;
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

Test case2
8 9
0 2 7
1 0 1
1 3 5
2 3 2
1 4 6
4 6 9
4 5 3
5 7 8
6 7 4
*/
