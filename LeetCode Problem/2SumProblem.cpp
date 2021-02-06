#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    int n=nums.size();
    unordered_map<int,int>hm;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int key = target-nums[i];
        if(hm.find(key)!=hm.end())
        {
            v={hm[key],i};
            return v;
        }
        hm[nums[i]]=i;
    }
    return v;
}
vector<int> TwoSum1(vector<int>&nums, int sum)
{
    int n= nums.size();
    unordered_set<int>hs;
    vector<int>v;
    for(int i=0;i<=n-1;i++)
    {
        int a = nums[i];
        int b = sum-a;
        if(hs.find(b)!=hs.end())
        {
            v.push_back(a);
            v.push_back(b);
            break;
        }
        else
            hs.insert(a);
    }
    hs.clear();
    return v;
}
main()
{
    int n;
    cout<<"Enter no of element in array:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter element in array:";
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"\nEnter target element:";
    int target;
    cin>>target;
    vector<int>res = twoSum(v,target);
    cout<<"\nIndex of these numbers are: ";
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<"  ";
    res.clear();
    cout<<endl<<endl;
    res = TwoSum1(v,target);
    cout<<"Two element whose sum is equal to given sum is:"<<endl;
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<"  ";
    res.clear();
    v.clear();
}
