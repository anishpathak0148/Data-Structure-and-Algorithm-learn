#include<bits/stdc++.h>
using namespace std;
class GraphTraverse
{
private:
    int V;
    list<int>*adj;
public:
    GraphTraverse(int v)
    {
        V=v;
        adj=new list<int>[V];
    }

    void addEdge(int src,int dest,bool bidir=false)
    {
        adj[src].push_back(dest);
        if(bidir)
            adj[dest].push_back(src);
    }
    void DFS_Traverse(int s)    //s stands for start vertex.
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        //creating stack for DFS.
        stack<int>st;    //st is stack.
        visited[s]=true;
        st.push(s);
        while(!st.empty())
        {
            s=st.top();
            st.pop();
            cout<<"Checking adjacent vertex for vertex: "<<s<<endl;
            for(auto i=adj[s].begin(); i!=adj[s].end(); i++)
            {
                if(!visited[*i])
                {
                    cout<<"Visit and push:"<<*i<<endl;
                    visited[*i]=true;
                    st.push(*i);
                }
            }
        }
    }
};

main()
{
    GraphTraverse g(6);
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

    g.DFS_Traverse(0);

    cout<<endl;
    cout<<endl;
    GraphTraverse g1(5);
    g1.addEdge(0,1,true);
    g1.addEdge(0,4,true);
    g1.addEdge(1,2,true);
    g1.addEdge(1,3,true);
    g1.addEdge(2,3,true);
    g1.addEdge(3,4,true);

    g1.DFS_Traverse(0);

}

