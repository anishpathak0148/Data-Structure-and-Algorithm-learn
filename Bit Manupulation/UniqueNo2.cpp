#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
        int arr[32]={0};
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x = nums[i];
            int j=0;
            while(x > 0)
            {
                arr[j] = x&1;
                j++;
                x = x>>1;
            }
        }
        int ans=0;
        long pos=1;
        for(int i=0;i<32;i++)
        {
            arr[i] %= 3;
            ans += arr[i]*pos;
            pos = pos << 1;
        }
        return ans;
    }
main()
{
    vector<int>v = {2,2,3,2};
    int ans = singleNumber(v);
    cout<<"Ans: "<<ans;
}
