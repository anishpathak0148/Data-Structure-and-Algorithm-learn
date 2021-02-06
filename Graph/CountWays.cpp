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

    void addEdge(int s, int d, bool bidir=false)
    {
        adj[s].push_back(d);
        if(bidir)
            adj[d].push_back(s);
    }
    int CountWays(int s)
    {
        bool *visited = new bool[V]{0};
        queue<int>q;
        visited[s]=true;
        q.push(s);
        int count=0;
        while(!q.empty())
        {
            s=q.front();
            q.pop();
            count+=1;
            for(auto it=adj[s].begin();it!=adj[s].end();it++)
            {
                if(!visited[*it])
                {
                    q.push(*it);
                    visited[*it]=true;
                }
            }
        }
        return count;
    }
};

int main() {
    cout<<"Enter input:"<<endl;
	int n, m;
	cin >> n >> m;
	Graph g(n);
    for(int i = 0;i < m; i++) {
		int x, y;
		cin >> x >> y;
        g.addEdge(x-1,y-1);
	}
    int s;
    cin>>s;
    cout<<g.CountWays(s);

}
