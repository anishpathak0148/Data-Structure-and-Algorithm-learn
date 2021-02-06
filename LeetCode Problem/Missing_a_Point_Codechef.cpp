#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long,long>P1, pair<long,long>P2)
{
    return P1.first <= P2.first;
}
int main() {
	// your code goes here
	cout<<"Enter Inputs..."<<endl;
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector< pair<long,long>> v;
	    for(int i=0; i<4*n-1;i++)
	    {
	        long x,y;
	        cin>>x>>y;
	        v.push_back(make_pair(x,y));
	    }
	    sort(v.begin(),v.end(),cmp);
	    long temp_y = 0;
	    int i=0;
	    for(i=0;i<4*n-2;i=i+2)
	    {
	        if(v[i].first == v[i+1].first)
	        {
	            temp_y = abs(v[i+1].second - v[i].second);
	        }
	        else
	        {
	            break;
	        }
	    }
	    long temp_x = v[i].first;
	    temp_y = v[i].second + temp_y;
	    cout<<temp_x<<" "<<temp_y;
	}
	return 0;
}

