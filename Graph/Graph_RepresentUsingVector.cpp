#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void DFS_helper(vector<int>adj[], vector<bool> &visited, int start)
{
    visited[start]=true;
    cout<<"Visit "<<start<<endl;
    for(int i=0;i<adj[start].size();i++)
    {
        if(visited[adj[start][i]] ==false)
        {
            DFS_helper(adj, visited, adj[start][i]);
        }
    }
}
void DFS_traverse(vector<int>adj[],int V)
{
    vector<bool> visited(V,false);
    for(int u=0;u<V;u++)
    {
        if(visited[u]==false)
            DFS_helper(adj,visited,u);
    }
}
main()
{
    int V=5;
    vector<int> *adj = new vector<int>[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS_traverse(adj, V);
}
