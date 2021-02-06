#include<iostream>
#include<list>
#include<queue>
using namespace std;
struct minHeapNode
{
    int data;
    bool visit;
    minHeapNode *left,*right;
    minHeapNode(int data, bool visit)
    {
        this->data = data;
        this->visit = visit;
        left=right=nullptr;
    }
};
struct compare {

    bool operator()(minHeapNode* l, minHeapNode* r)

    {
        return (l->data > r->data);
    }
};
class Graph
{
    int V;
    list< pair<int,int> > *adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new list< pair<int,int>>[V];
    }
    void addEdge(int u, int v, int w, bool bidir=true)
    {
        adj[u].push_back(make_pair(v,w));
        if(bidir)
        {
            adj[v].push_back(make_pair(u,w));
        }
    }
    void printGraph()
    {
        cout<<"Graph Adjacency list is:"<<endl;
        for(int i=0;i<V;i++)
        {
            cout<<i<<"  -> ";
            for(auto ele : adj[i])
            {
                cout<<"("<<ele.first<<", "<<ele.second<<"), ";
            }
            cout<<endl;
        }
    }
    void dijkastra(int start)
    {
        int *distance = new int[V];
        bool *visited = new bool[V];
        priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap;
        for(int i=0;i<V;i++)
        {
            distance[i] = 999999;
            visited[i] = false;
        }
        distance[start] = 0;

    }
};
main()
{
    int V;
    cout<<"No of vertex in graph:";
    cin>>V;
    Graph g(V);
    int E;
    cout<<"Enter No of Edges:";
    cin>>E;
    for(int i=0;i<E;i++)
    {
        int src,dest,wt;
        cin>>src>>dest>>wt;
        g.addEdge(src,dest,wt);
    }
    g.printGraph();
    int source;
    //cout<<"Enter Source vertex to implement Dijkashtra Algorithm:";
    //cin>>source;
    //g.Dijkashtra(source);
}
