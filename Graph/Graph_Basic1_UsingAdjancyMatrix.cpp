#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Graph
{
    int V;
    int **adj;
public:
    Graph(int V)
    {
        this->V = V;
        adj = new int* [V];
        for(int i=0;i<V;i++){
            adj[i] = new int[V];
            for(int j=0;j<V;j++)
                adj[i][j]=0;
        }
    }
    void addEdge(int u, int v, bool bidir=true)
    {
        adj[u][v]=1;
        if(bidir)
            adj[v][u]=1;
    }
    void PrintAdjacencyMatrix()
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                cout<<adj[i][j]<<"  ";
            cout<<endl;
        }
    }
    void DFS_traverse(int start)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;

        stack<int>st;
        visited[start]=true;
        st.push(start);
        while(!st.empty())
        {
            start = st.top();
            st.pop();
            cout<<start<<", ";
            for(int j=0;j<V;j++)
            {
                if(!visited[j])
                {
                    if(adj[start][j]==1){
                        st.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
        delete [] visited;
    }
    void BFS_traverse(int start)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;

        queue<int>q;
        visited[start]=true;
        q.push(start);
        while(!q.empty())
        {
            start = q.front();
            q.pop();
            cout<<start<<", ";
            for(int j=0;j<V;j++)
            {
                if(!visited[j])
                {
                    if(adj[start][j]==1){
                        q.push(j);
                        visited[j]=true;
                    }
                }
            }
        }
        delete [] visited;
    }
};
main()
{
    /*
    int *arr = new int[5];
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Execute above.."<<endl;
    */
    int n;
    cout<<"Enter no of vertex: ";
    cin>>n;
    Graph g(n);
    int E;
    cout<<"Enter no of edges: ";
    cin>>E;
    cout<<"Enter edge in (Source Destination) format:"<<endl;
    for(int i=0;i<E;i++)
    {
        int src, dest;
        cin>>src>>dest;
        g.addEdge(src,dest);
    }
    cout<<"Adjacency Matrix is:"<<endl;
    g.PrintAdjacencyMatrix();

    int start;
    cout<<"\nEnter Starting node:";
    cin>>start;
    cout<<"\nDFS traverse of Graph is:"<<endl;
    g.DFS_traverse(start);
    cout<<endl;
    cout<<"\nBFS traverse of Graph is:"<<endl;
    g.BFS_traverse(start);
}
