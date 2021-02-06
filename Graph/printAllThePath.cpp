/*
this problem print all the path between source and destination.
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

    void printPathHelper(int src, int dest, bool visited[], int path[], int &path_index)
    {
        visited[src]=true;
        path[path_index]=src;
        path_index++;
        if(src==dest)
        {
            for(int i=0;i<path_index;i++)
            {
                cout<<path[i]<<" -> ";
            }
            cout<<endl;
        }
        else
        {
            list<int>::iterator i;
            for(i=adj[src].begin(); i!=adj[src].end(); ++i)
            {
                if(!visited[*i])
                {
                    printPathHelper(*i,dest,visited,path,path_index);
                }

            }
        }
        path_index--;
        visited[src]=false;
    }

    void printAllPath(int src, int dest)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        //create an array for path.
        int *path = new int[V];
        int path_index=0;   //initially path index=0.
        cout<<"Total path between "<<src<<" to "<<dest<<" is:"<<endl;
        printPathHelper(src,dest,visited,path, path_index);
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

    g.printAllPath(0,3);
}

