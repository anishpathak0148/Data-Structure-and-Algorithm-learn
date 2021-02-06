#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int>*adj;
public:
    Graph(int v)
    {
        V=v;
        adj = new list<int>[V];
    }
    addEdge(int src,int dest)
    {
        adj[src].push_back(dest);
    }

    void DFS_helper(int s, bool *visited)
    {
        cout<<"Visiting node:"<<s<<endl;
        visited[s]=true;

        for(auto i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                cout<<"going to vertex "<<*i<<" from vertex "<<s<<endl;
                DFS_helper(*i,visited);
            }
        }
    }
    void DFS_traverse(int s)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        DFS_helper(s,visited);
    }
};
main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);

    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(1,4);

    g.addEdge(2,0);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(3,5);

    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(4,5);

    g.addEdge(5,3);
    g.addEdge(5,4);

    g.DFS_traverse(0);
}

