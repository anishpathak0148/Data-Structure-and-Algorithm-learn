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

    void BFS_traverse(int start)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        queue<int>q; //creating a queue q.
        visited[start]=true;
        q.push(start);
        while(!q.empty())
        {
            start=q.front();
            q.pop();
            cout<<"Checking adjacent vertices for vertex:"<<start<<endl;
            for(auto i=adj[start].begin(); i!=adj[start].end(); i++)
            {
                if(!visited[*i])
                {
                    cout<<"Visit and enqueue:"<<*i<<endl;
                    visited[*i]=true;
                    q.push(*i);
                }
            }
        }
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

    g.BFS_traverse(0);
}

