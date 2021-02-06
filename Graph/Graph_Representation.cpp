#include<bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int V;
    list<int>*adj;
public:
    Graph(int v)
    {
        V=v;
        adj = new list<int>[V];
    }

    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
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
}
