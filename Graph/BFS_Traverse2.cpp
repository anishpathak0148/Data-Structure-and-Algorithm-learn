#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<string,list<string>>adjList;
public:
    void addEdge(string u, string v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        for(auto it=adjList.begin();it!=adjList.end();it++)
        {
            string key = it->first;
            cout<<key<<" -> ";
            for(auto val =it->second.begin(); val!=it->second.end();val++)
            {
                cout<<*val<<", ";
            }
            cout<<endl;
        }
    }
    void BFS_traverse(string start)
    {
        //bool *visited = new bool[adjList.size()];
        map<string, bool>visited;
        for(auto it=adjList.begin();it!=adjList.end();it++)
        {
            string v = it->first;
            visited[v]=false;
        }
        queue<string>q;
        q.push(start);
        visited[start]=true;
        while(!q.empty())
        {
            string temp=q.front();
            q.pop();
            cout<<temp<<"  -> ";
            for(string neighbor : adjList[temp])
            {
                if(!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
};
main()
{
    Graph g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Patna");
    g.addEdge("Delhi","Bangalore");
    g.addEdge("Delhi","Chandigarh");
    g.addEdge("Amritsar","Patna");
    g.printAdjList();
    cout<<endl;
    cout<<"BFS Traverse of Graph is:"<<endl;
    g.BFS_traverse("Delhi");
}
