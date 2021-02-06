#include<bits/stdc++.h>
using namespace std;
#define INFINITE 99999
class Graph
{
    int V;
    int **adjMatrix;
public:
    // In constructor box we write code of Adjacency Matrix representation of Graph.
    Graph(int v)
    {
        V=v;
        adjMatrix = new int*[V];       // 2-D dynamic array representation.
        for(int i=0;i<V;i++)
        {
            adjMatrix[i] = new int[V];
            for(int j=0;j<V;j++)
            {
                if(j==i)
                    adjMatrix[i][j]=0;
                else
                {
                    adjMatrix[i][j]=INFINITE;
                }
            }
        }
    }

    void addEdge(int u, int v, int wt)
    {
        adjMatrix[u][v] = wt;
        adjMatrix[v][u] = wt;
    }

    void printAdjMatrix()
    {
        cout<<"Adjacency matrix is:"<<endl;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adjMatrix[i][j]==INFINITE)
                    cout<<"INF"<<"\t";
                else{
                cout<<adjMatrix[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
    }

    int findMinVertex(int *distance, bool *visited, int V)
    {
        int minVertex=-1;
        for(int i=0;i<V;i++)
        {
            if(!visited[i] && (minVertex==-1 || distance[i]<distance[minVertex]))
            {
                minVertex = i;
                //break;
            }
        }
        return minVertex;
    }
    void DijkashtraAlgo(int src)
    {
        int *distance = new int[V];
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            distance[i]=INFINITE;
            visited[i]=false;
        }
        distance[src]=0;
        for(int i=0;i<V-1;i++)
        {
            int minVertex = findMinVertex(distance,visited,V);
            //cout<<"Min Vertex:"<<minVertex<<endl;
            visited[minVertex]=true;
            for(int j=0;j<V;j++)
            {
                if(adjMatrix[minVertex][j]!=0 && !visited[j])
                {
                    int dist = distance[minVertex] + adjMatrix[minVertex][j];
                    if(dist < distance[j])
                        distance[j] = dist;
                }
            }
        /*
            for(int i=0;i<V;i++)
        {
            cout<<i<<"  "<<distance[i]<<endl;
        }
        */
        }
        //now print the shortest distance list.
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
    g.printAdjMatrix();
    int source;
    cout<<"Enter Source vertex to implement Dijkashtra Algorithm:";
    cin>>source;
    g.DijkashtraAlgo(source);

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

*/
