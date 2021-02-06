/*
for Topological sorting of graph, graph should be DAG.
    DAG = Directed Acyclic Graph.
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
        adj=new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
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

    void topoSortHelper(int v, bool *visited, stack<int>&st)
    {
        visited[v]=true;
        for(auto it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visited[*it])
            {
                topoSortHelper(*it,visited,st);
            }
        }
        st.push(v);
    }
    void TopologicalSort()
    {
        if(isCycle()==false)
        {
            bool *visited = new bool[V]{0};
            stack<int>st;
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    topoSortHelper(i,visited,st);
                }
            }
            cout<<"Topological sorting order:"<<endl;
            while(!st.empty())
            {
                cout<<st.top()<<"  ";
                st.pop();
            }
        }
        else
            cout<<"Graph is not DAG."<<endl;
    }
};
main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    g.TopologicalSort();

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
    g1.TopologicalSort();

    cout<<endl;
    cout<<endl;
    Graph g2(5);
    g2.addEdge(0,1);
    g2.addEdge(0,2);
    g2.addEdge(1,2);
    g2.addEdge(2,0);
    g2.addEdge(2,3);
    g2.addEdge(3,3);
    g2.TopologicalSort();
}
