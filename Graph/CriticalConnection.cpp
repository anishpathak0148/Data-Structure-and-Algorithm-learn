#include<bits/stdc++.h>
using namespace std;
int t=0;
vector<bool>visited;
vector<int>discover;
vector<int>lowest;
vector<vector<int>>graph;
vector<pair<int,int>>res;
void dfs(int v,int parent)
{
    visited[v]=true;
    discover[v] = lowest[v] = t++;
    for(auto e:graph[v])
    {
        if(e==parent)
            continue;
        else if(!visited[e]){
            dfs(e,v);

            lowest[v] = min(lowest[v],lowest[e]);
            if(discover[v]<lowest[e])
            {
                res.push_back(make_pair(v+1,e+1));
                //cout<<v+1<<"  "<<e+1<<" "<<endl;
            }
        }
        else
        {
            lowest[v] = min(lowest[v],discover[e]);
        }
    }
}
vector<pair<int,int>> criticalConnection(vector<pair<int,int>>connections,int n, int e)
{
    graph.resize(n);
    visited.resize(n,false);
    discover.resize(n,0);
    lowest.resize(n,0);
    for(auto ele:connections)
    {
        int x=ele.first;
        int y=ele.second;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    //print the graph connection..
    cout<<"Graph structure is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(auto ele:graph[i])
        {
            cout<<ele<<", ";
        }
        cout<<endl;
    }
    //now call the dfs with parent -1
    dfs(0,-1);
    return res;
}
main()
{
    int n,E;
    cout<<"Enter no of nodes and connections:"<<endl;
    cin>>n>>E;
    vector<pair<int,int>>con;
    cout<<"Enter connection of Network:"<<endl;
    for(int i=1;i<=E;i++)
    {
        int x,y;
        cin>>x>>y;
        con.push_back(make_pair(x,y));
    }
    vector<pair<int,int>>critical = criticalConnection(con,n,E);
    cout<<"Critical connection are.."<<endl;
    for(auto ele : critical)
    {
        cout<<ele.first<<"  "<<ele.second<<endl;
    }
}
/*
Test case:
5 5
1 2
1 3
1 4
3 4
4 5
output:
1 2
4 5

Test Case:
4 4
1 2
2 3
1 3
2 4
output:
2 4
*/
