#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list< pair<int,int>>*adj;
    int INF=99999;
public:
    Graph(int v)
    {
        V=v;
        adj = new list<pair<int,int>>[V];
    }
    void addEdge(int u,int v,int wt, bool bidir=true)
    {
        adj[u].push_back(make_pair(v,wt));
        if(bidir)
            adj[v].push_back(make_pair(u,wt));
    }

    int findMinVertex(int *distance,bool *visited)
    {
        int minVertex=-1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
            {
                minVertex=i;
            }
        }
        return minVertex;
    }
    void Dijkashtra(int src)
    {
        int *distance = new int[V];
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            distance[i]=INF;
            visited[i]=false;
        }
        distance[src]=0;

        for(int i=0;i<V-1;i++)
        {
            int minVertex = findMinVertex(distance,visited);
            visited[minVertex]=true;
            for(auto it=adj[minVertex].begin();it!=adj[minVertex].end();it++)
            {
                int v=it->first;
                int w=it->second;
                if(w!=0 && !visited[v])
                {
                    int dist = distance[minVertex] + w;
                    if(dist<distance[v])
                        distance[v]=dist;
                }
            }
        }
        cout<<"\nVertex  Shortest distance from "<<src<<endl;
        for(int i=0;i<V;i++)
        {
            cout<<i<<" \t "<<distance[i]<<endl;
        }
        delete [] visited;
        delete [] distance;
    }
};
main()
{
    int V;
    cout<<"No of vertex in graph:";
    cin>>V;
    Graph g(V);
    int E;
    cout<<"Enter No of Edges:";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int src,dest,wt;
        cin>>src>>dest>>wt;
        g.addEdge(src,dest,wt);
    }
    //g.printAdjMatrix();
    int source;
    cout<<"Enter Source vertex to implement Dijkashtra Algorithm:";
    cin>>source;
    g.Dijkashtra(source);

}
/*
Test case1:
5
7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4

Output1:
0 0
1 4
2 6
3 9
4 13

Test case2:
9
14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
Output2:
0 0
1 4
2 12
3 19
4 21
5 11
6 9
7 8
8 14
*/
