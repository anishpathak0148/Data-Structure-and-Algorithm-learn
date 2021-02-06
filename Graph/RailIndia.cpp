/*
This problem find the total cost from different path to reach the destination from source.
this same as printAllThePath problem.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> mapStation(string arr[],int n)
{
    vector<int>v(n);
    map<string,int>m;
    m[arr[0]]=0;
    for(int i=1;i<n;i++)
    {
        if(m[arr[i]]<=m[arr[i-1]])
            continue;
        else
        {
            m[arr[i]]=m[arr[i-1]]+1;
        }
    }
    for(int i=0;i<n;i++)
    {
        v[i]=m[arr[i]];
    }
    return v;
}

class Graph
{
    int V;
    list<pair<int,int>>*adj;
public:
    Graph(int v)
    {
        V=v;
        adj = new list<pair<int,int>>[V];
    }
    void addEdge(int src,int dest,int c)
    {
        pair<int,int>p=make_pair(dest,c);
        adj[src].push_back(p);
    }

    void printPathHelper(int src, int dest, bool visited[], int path[], int &path_index, int &result)
    {
        visited[src]=true;
        path[path_index]=src;
        path_index++;
        if(src==dest)
        {
            for(int i=0;i<path_index;i++)
            {
                cout<<path[i]<<"  ";
            }
            cout<<"Total cost:"<<result;
            //result=0;
            cout<<endl;
        }
        else
        {
            //list<pair<int,int>>::iterator i;
            for(auto i=adj[src].begin(); i!=adj[src].end(); ++i)
            {
                int v=i->first;
                int w=i->second;
                if(!visited[v])
                {
                    result+=w;
                    printPathHelper(v,dest,visited,path,path_index,result);
                    result-=w;
                }

            }
        }
        path_index--;
        visited[src]=false;
    }

    void printAllPath(int src, int dest)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        //create an array for path.
        int *path = new int[V];
        int path_index=0;   //initially path index=0.
        cout<<"Total path between "<<src<<" to "<<dest<<" is:"<<endl;
        int result=0;
        printPathHelper(src,dest,visited,path, path_index,result);
    }
};
main()
{
    //string A,B;
    int A,B;
    cout<<"Enter two Station in number:"<<endl;
    cin>>A>>B;
    cout<<"\nEnter n for no of routes:";
    int n;
    cin>>n;
    //string Start[n],End[n];
    int Start[n],End[n];
    int cost[n];
    cout<<"Enter Starting Station Ending Station and Cost to reach that Station:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>Start[i]>>End[i]>>cost[i];
    }
    Graph g(10);
    for(int i=0;i<n;i++)
    {
        g.addEdge(Start[i],End[i],cost[i]);
    }
    g.printAllPath(A,B);
}
