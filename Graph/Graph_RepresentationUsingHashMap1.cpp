/*
Graph Representation of a unweighted graph using HashMap of generic data-types.
generic data-types means that like string,char,int etc type.so we use template class.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>>adjList;
public:
    Graph()
    {

    }
    void addEdge(T src, T dest, bool bidir=true)
    {
        adjList[src].push_back(dest);
        if(bidir)
            adjList[dest].push_back(src);

    }
    void printAdjList()
    {
        for(auto row : adjList)
        {
            T key = row.first;
            cout<<key<<" -> ";
            for(T element : row.second)
            {
                cout<<element<<", ";
            }
            cout<<endl;
        }
    }
};

main()
{
    Graph<string>g;
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Delhi","Patna");
    g.addEdge("Delhi","Bangalore");
    g.addEdge("Delhi","Chandigarh");
    g.addEdge("Amritsar","Patna");
    g.printAdjList();
}
