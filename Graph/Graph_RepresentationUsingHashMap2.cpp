/*
Graph Representation of a weighted graph using HashMap of generic data-types.
generic data-types means that like string,char,int etc type.so we use template class.
*/

#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
    map<T, list< pair<T, int>>>adjList;
public:
    void addEdge(T src, T dest,int wt, bool bidir=true)
    {
        adjList[src].push_back(make_pair(dest,wt));
        if(bidir)
            adjList[dest].push_back(make_pair(src,wt));

    }
    void printAdjList()
    {
        for(auto row : adjList)
        {
            T key = row.first;
            cout<<key<<" -> ";
            for(auto value : row.second)
            {
                T element = value.first;
                int w = value.second;
                cout<<"( "<<element<<", "<<w<<" )"<<", ";
            }
            cout<<endl;
        }
    }
};

main()
{
    Graph<string>g;
    g.addEdge("Amritsar","Delhi",500);
    g.addEdge("Amritsar","Jaipur",850);
    g.addEdge("Delhi","Patna",1100);
    g.addEdge("Delhi","Bangalore",1500);
    g.addEdge("Delhi","Chandigarh",270);
    g.addEdge("Amritsar","Patna",1300);
    g.printAdjList();
}

