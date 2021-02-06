/*
This problem based on traveling salesman problem which finds the cost of minimum Hamiltonion cycle.
Concept Used: Recursion, Branch and Bound, DP, Bit-masking.
Here we discuss the problem using recursion and bit-masking.
*/
#include<iostream>
using namespace std;

int v=5;
int edge[10][10]={{0,10,20,20,15},
                {10,0,5,10,5},
                {20,5,0,8,15},
                {20,10,8,0,10},
                {15,5,15,10,0}

                };

/*
int v=4;
int edge[10][10]={{0,20,42,25},
                {20,0,30,34},
                {42,30,0,10},
                {25,34,10,0}
                };
*/

int visited_All = (1<<v)-1;

int tsp(int mask, int pos)
{
    if(mask==visited_All)
    {
        return edge[pos][0];
    }
    int ans =99999;
    for(int city=0;city<v;city++)
    {
        if((mask & (1<<city)) ==0)
        {
            int newans = edge[pos][city] + tsp((mask |(1<<city)), city);
            ans = min(ans,newans);
        }
    }
    return ans;
}
main()
{
    cout<<"Minimum cost of TSP is: ";
    int mask=1; //00001
    int initial_pos=0;
    cout<<tsp(mask,initial_pos);

}
