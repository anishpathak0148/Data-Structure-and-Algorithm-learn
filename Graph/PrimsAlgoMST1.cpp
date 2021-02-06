#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<pair<int,int>> *adj;
public:
    Graph(int v)
    {
        V=v;
        adj = new vector<pair<int,int>>[V];
    }
    void addEdge(int u, int v, int wt, bool bidir=true)
    {
        adj[u].push_back(make_pair(v,wt));
        if(bidir)
            adj[v].push_back(make_pair(u,wt));
    }
    pair<int,int> findMinEdge()
    {
        int minCost=0;
        int start=-1;
        int End =0;
        for(int i=0;i<V;i++)
        {
            for(auto it=adj[i].begin();it!=adj[i].end();it++)
            {
                int v=it->first;
                int w=it->second;
                if(minCost > w)
                {
                    minCost=w;
                    start=i;
                    End=v;
                }
            }
        }
        pair<int,int>  p= make_pair(start,End);
        return p;
    }
};
main()
{
    Graph g(5);
    g.addEdge(0,1,10);
    g.addEdge(0,4,20);
    g.addEdge(1,2,30);
    g.addEdge(1,3,40);
    g.addEdge(1,4,50);
    g.addEdge(2,3,60);
    g.addEdge(3,4,70);
}
