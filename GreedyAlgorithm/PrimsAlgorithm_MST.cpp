#include<iostream>
#include<list>
#define INF 99999
using namespace std;
struct Edge
{
    int src,dest,weight;
};
class Graph
{
    int V;
    list<pair<int,int>> *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list< pair<int,int> >[V];
    }
    void addEdge(int u, int v, int w, bool bidir=true)
    {
        adj[u].push_back(make_pair(v,w));
        if(bidir)
        {
            adj[v].push_back(make_pair(u,w));
        }
    }

    int minKey(int *mstSet, int *KeySet)
    {
        int Min = INF, minIndex;

    }
    Edge* Prims_Mst(int start=0)
    {
        bool *mstSet = new bool[V];
        int *parent = new int[V];
        int *KeySet = new int[V];
        for(int i=0;i<V;i++)
        {
            mstSet[i]=false;
            parent[i]=i;
            KeySet[i]=INF;
        }
        mstSet[start] = true;
        KeySet[start] = 0;
        for(auto it=adj[start].begin(); it!=adj[start].end(); it++)
        {
            int v = it->first;
            int w = it->second;
            if(!mstSet[v])
            {
                KeySet[v]=w;
                parent[v]=start;
            }
        }
    }

};

main()
{
    int n,e;
    cout<<"Enter no of vertex and edges :"<<endl;
    cin>>n>>e;
    Graph g(n);
    for(int i=0;i<e;i++)
    {
        int src,dest,weight;
        cin>>src>>dest>>weight;
        g.addEdge(src,dest,weight);
    }
    Edge *mst = new Edge[n-1];
    mst = g.Prims_Mst();
}
