/*
this problem find the cycle detection in an Undirected Graph.
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
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isCycleHelper(int v, bool visited[], int parent)
    {
        visited[v]=true;
        list<int>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visited[*it])
            {
                if(isCycleHelper(*it,visited,v))
                {
                    return true;
                }
            }
            else if(*it!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }

        for(int u=0;u<V;u++)
        {
            if(!visited[u])
            {
                if(isCycleHelper(u,visited,-1))
                    return true;
            }
        }
        return false;
    }

};
main()
{
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(3,4);
    cout<<"is Graph g1 contain any cycle :";
    if(g1.isCycle())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


    cout<<endl;
    cout<<endl;
    Graph g2(6);
    g2.addEdge(0,1);
    g2.addEdge(0,4);
    g2.addEdge(1,2);
    g2.addEdge(2,3);
    g2.addEdge(2,5);
    cout<<"is Graph g2 contain any cycle :";
    if(g2.isCycle())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
