#include<bits/stdc++.h>
#define INF 99999
using namespace std;
void printGraph(vector<vector<int>>adj)
{
    for(int i=0;i<adj.size();i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j]==INF)
                cout<<"INF\t";
            else
                cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
}
main()
{
    int V,E;
    cout<<"Enter no of vertex and Edges:"<<endl;
    cin>>V>>E;
    //prepare Adjacent matrix for graph.
    vector<vector<int>> adj(V,vector<int>(V,INF));
    for(int i=0;i<V;i++)
    {
        adj[i][i] = 0;  //distance self loop edges is always zero.
    }
    cout<<"Enter Edges of Graph in (Src Dest Cost) format:"<<endl;
    for(int i=0;i<E;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        adj[u][v] = d;
    }
    cout<<"\n Initial Cost of All Pair Shortest Path is: "<<endl;
    printGraph(adj);
}
