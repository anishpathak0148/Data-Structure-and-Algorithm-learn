#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct Edges
{
    int src;
    int dest;
    int weight;
    Edges(int u,int v,int w)
    {
        src=u;
        dest=v;
        weight=w;
    }
};

struct DisjointSet
{
    int *parent,*rank;
    int n;
    DisjointSet(int n)
    {
        this->n=n;
        parent=new int[n+1];
        rank=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        rank[i]=0;
        parent[i]=i;
    }
    }
    int find(int x)
    {
        if(x!=parent[x])
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    //Union by rank
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);
        if(rank[x] > rank[y])
        {
            parent[y]=x;
        }
        else
            parent[x]=y;
        if(rank[x]==rank[y])
            rank[y]++;
    }
};

class Graph
{
public:
    int V,E;
    Graph(int V,int E)
    {
        this->V=V;
        this->E=E;
    }
    vector<struct Edges>pairs;
    void addEdge(int u,int v,int w)
    {
        pairs.push_back(Edges(u,v,w));
    }
    bool cmp(Edges &e1, Edges &e2)
    {
        return e1.weight<e2.weight;
    }
    vector<Edges>resultMST;
    void KruskalMST()
    {
        int mst_wt=0;
        //Sort the pairs according to their edge weight.
        sort(pairs.begin(),pairs.end(),cmp);
        //Create disjoint sets
        DisjointSet ds(V);
        int i=0,mst_edge=0;
        while(mst_edge < V-1 || i<E)
        {
            Edges currentEdge = pairs[i];
            int u=currentEdge.src;
            int v=currentEdge.dest;
            int wt=currentEdge.weight;

            int set_u = ds.find(u);
            int set_v = ds.find(v);

            if(set_u==set_v)
            {
                resultMST.push_back(currentEdge);
                mst_wt+=wt;
                ds.Union(set_u,set_v);
                mst_edge++;
            }
           i++;
        }
        cout<<"\nMinimum Spanning Tree is:"<<endl;
        cout<<"Source\tDestination\tWeight";
        for(i=0;i<mst_edge;i++)
        {
            cout<<resultMST[i].src<<"\t"<<resultMST[i].dest<<"\t"<<resultMST[i].weight<<endl;
        }
        cout<<"\nWeight of MST is: "<<mst_wt;
    }
};

main()
{
    Graph g(7,9);
    g.addEdge(1,2,4);
    g.addEdge(7,2,2);
    g.addEdge(6,2,3);
    g.addEdge(6,5,1);
    g.addEdge(5,3,20);
    g.addEdge(4,3,6);
    g.addEdge(1,4,7);
    g.addEdge(2,5,2);
    g.addEdge(2,3,1);
    g.KruskalMST();
}
