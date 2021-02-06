/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
        set<vector<int>>s;
        //This method takes O(n^3) time.
        for(int i=0;i<=n-3;i++)
        {
            for(int j=i+1; j<=n-2;j++)
            {
                for(int k=j+1;k<=n-1;k++)
                {
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        vector<int>a;
                        a.push_back(nums[i]);
                        a.push_back(nums[j]);
                        a.push_back(nums[k]);
                        sort(a.begin(),a.end());    //here this takes O(k) time because here no of element = 3.
                        s.insert(a);
                    }
                }
            }
        }
        vector<vector<int>>v;
        for(auto it = s.begin(); it!=s.end();it++)
        {
            v.push_back(*it);
        }
        return v;
}

vector<vector<int>> threeSumOptimize(vector<int>& nums) {
    int n = nums.size();
    //This method take O(n^2) time.
        set<vector<int>>S;

        for(int i=0; i<=n-2;i++)
        {
            unordered_set<int>hs;    //we create a hashSet.
            for(int j=i+1; j<=n-1;j++)
            {
                //a = nums[i]
                //b = nums[j]
                // a+b+c = 0 then c = -(a+b);
                int c = -1 *(nums[i] + nums[j]);
                if(hs.find(c) != hs.end())
                {
                    vector<int>v1;
                    v1.push_back(nums[i]);
                    v1.push_back(nums[j]);
                    v1.push_back(c);
                    sort(v1.begin(), v1.end());
                    S.insert(v1);
                }
                else
                {

                    hs.insert(nums[j]);
                }
            }
        }
        vector<vector<int>>v;
        for(auto it = S.begin(); it!=S.end();it++)
        {
            v.push_back(*it);
        }
        return v;
}
vector<vector<int>> AllTriplates(vector<int>& nums) {
    int n = nums.size();
    //first sort the array.
        sort(nums.begin(),nums.end());
        set<vector<int>>S;
        for(int i=0;i<n-1;i++)
        {
            int l = i+1;
            int r = n-1;
            int x = nums[i];
            while(l<r){
                if(x+ nums[l]+nums[r]==0)
                {
                    vector<int>v1;
                    v1.push_back(x);
                    v1.push_back(nums[l]);
                    v1.push_back(nums[r]);
                    S.insert(v1);
                    l++;
                    r--;
                }
                else if(x+ nums[l]+nums[r]<0)
                {
                    l++;
                }
                else
                    r--;
            }
        }
        vector<vector<int>>v;
        for(auto it = S.begin(); it!=S.end();it++)
        {
            v.push_back(*it);
        }
        return v;
}
main()
{
    vector<int>arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res1 = threeSum(arr);
    vector<vector<int>> res2 = threeSumOptimize(arr);
    vector<vector<int>> res3 = AllTriplates(arr);
    cout<<"All Triplets Using basic Approach with O(n^3) time is:"<<endl;
    cout<<"["<<endl;
    for(int i=0;i<res1.size();i++)
    {
        cout<<"   [ ";
        for(int j=0;j<res1[i].size();j++)
            cout<<res1[i][j]<<"  ";
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;

    cout<<endl<<endl;
    cout<<"All Triplets Using Optimized HashSet Approach with O(n^2) time and O(n) space is:"<<endl;
    cout<<"["<<endl;
    for(int i=0;i<res2.size();i++)
    {
        cout<<"   [ ";
        for(int j=0;j<res2[i].size();j++)
            cout<<res2[i][j]<<"  ";
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;

    cout<<endl<<endl;
    cout<<"All Triplets Using Optimized Approach with O(n^2) time and O(1) space is:"<<endl;
    cout<<"["<<endl;
    for(int i=0;i<res3.size();i++)
    {
        cout<<"   [ ";
        for(int j=0;j<res3[i].size();j++)
            cout<<res3[i][j]<<"  ";
        cout<<"]"<<endl;
    }
    cout<<"]"<<endl;
}
