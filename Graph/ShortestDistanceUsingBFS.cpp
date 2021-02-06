#include <bits/stdc++.h>
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

    void addEdge(int s, int d, bool bidir=true)
    {
        adj[s].push_back(d);
        if(bidir)
            adj[d].push_back(s);
    }
    int ShortestDistance(int s, int t)
    {
        bool *visited = new bool[V];
        int *dist = new int[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            dist[i]=0;
        }
        queue<int>q;
        visited[s]=true;
        q.push(s);
        while(!q.empty())
        {
            s=q.front();
            q.pop();
            for(auto it=adj[s].begin();it!=adj[s].end();it++)
            {
                if(!visited[*it]){
                    q.push(*it);
                    visited[*it]=true;
                    dist[*it]=dist[s]+1;
                }
            }
        }
        return dist[t];
    }

};
int main(){
    cout<<"Enter input:"<<endl;
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u-1,v-1);
    }
    int s,t;
    cin>>s>>t;
    cout<<"Shortest distance is:";
    cout<<g.ShortestDistance(s-1,t-1);
	return 0;
}
