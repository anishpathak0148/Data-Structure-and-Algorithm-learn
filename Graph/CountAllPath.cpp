/*
this problem count all the path between source and destination.
in this problem we use backtracking approach.
*/
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
    void addEdge(int src,int dest)
    {
        adj[src].push_back(dest);
    }

    void countPathHelper(int src, int dest, bool visited[], int &path_count)
    {
        visited[src]=true;
        if(src==dest)
        {
            path_count++;
        }
        else
        {
            list<int>::iterator i;
            for(i=adj[src].begin(); i!=adj[src].end(); ++i)
            {
                if(!visited[*i])
                {
                    countPathHelper(*i,dest,visited,path_count);
                }

            }
        }
        visited[src]=false;
    }

    void countAllPath(int src, int dest)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        int path_count=0;
        countPathHelper(src,dest,visited, path_count);
        cout<<"Total path between "<<src<<" to "<<dest<<" is:"<<path_count;
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

    /*
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    */

    g.countAllPath(0,3);
}
