/*
this problem find the cycle in a Directed graph.
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
    void addEdge(int src, int dest)
    {
        adj[src].push_back(dest);
    }

    bool isCycleHelper(int v, bool visited[], bool recStack[])
    {
        if(visited[v]==false)
        {
            visited[v]=true;
            recStack[v]=true;
            list<int>::iterator it;
            for(it=adj[v].begin();it!=adj[v].end();it++)
            {
                if(!visited[*it])
                {
                    if(!visited[*it] && isCycleHelper(*it,visited,recStack))
                        return true;
                }
                else if(recStack[*it])
                    return true;
            }
        }
        recStack[v]=false;
        return false;
    }
    bool isCycle()
    {
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            recStack[i]=false;
        }
        for(int u=0;u<V;u++)
        {
            if(!visited[u])
            {
                if(isCycleHelper(u,visited,recStack))
                    return true;
            }
        }
        return false;
    }
    /*
    void test()
    {
        for(int i=0;i<V;i++)
        {
            list<int>::iterator it;
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                cout<<*it<<"\t";
            }
            cout<<endl;
        }
    }
    */
};
main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"is Graph g contain any cycle :";
    if(g.isCycle())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    //g.test();
    cout<<endl;
    cout<<endl;
    Graph g1(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,4);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(4,2);
    g1.addEdge(4,3);
    cout<<"is Graph g1 contain any cycle :";
    if(g1.isCycle())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
