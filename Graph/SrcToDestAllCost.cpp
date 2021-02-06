#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int,int>>adj[],int src,int dest,int wt)
{
    adj[src].push_back(make_pair(dest,wt));
}

void printAllCostHelper(vector<pair<int,int>>adj[],int src,int dest,vector<bool>visited, int path[],int &path_index,int &cost)
{
    visited[src]=true;
    path[path_index]=src;
    path_index++;
    if(src==dest)
    {
        for(int i=0;i<path_index;i++)
        {
            cout<<" -> "<<path[i]<<"  ";
        }
        cout<<"\t"<<cost;
        cout<<endl;
    }
    else
    {
        for(auto i=adj[src].begin(); i!=adj[src].end(); ++i)
        {
            int v=i->first;
            int w=i->second;
            if(!visited[v])
            {
                cost+=w;
                printAllCostHelper(adj,v,dest,visited,path,path_index,cost);
                cost-=w;
            }
        }
    }
    path_index--;
    visited[src]=false;
}
void AllCost(vector< pair<int,int>>adj[] ,int src,int dest,int V)
{
    vector<bool>visited(V,false);
    int *path= new int[V];
    int path_index=0;
    int cost=0;
    cout<<"Total path between "<<src<<" to "<<dest<<" is:"<<endl;
    printAllCostHelper(adj,src,dest,visited,path, path_index,cost);
}
main()
{
    int V=5;
    vector<pair<int,int>> *adj = new vector<pair<int,int>>[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    AllCost(adj,0,4,V);

}
