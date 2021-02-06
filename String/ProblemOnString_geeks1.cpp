/*
Minimum sum of squares of character counts in a given string after removing k characters
Last Updated: 29-04-2020
Given a string of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character. For example consider the string “saideep”, here frequencies of characters are s-1, a-1, i-1, e-2, d-1, p-1 and value of the string is 1^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2 = 9.

Expected Time Complexity: O(k*logn)

Examples:

Input :  str = abccc, K = 1
Output :  6
We remove c to get the value as 12 + 12 + 22

Input :  str = aaab, K = 2
Output :  2

*/

#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

struct compare {

    bool operator()(pair<char,int>p1, pair<char,int>p2)

    {
        return (p1.second < p2.second);
    }
};
//Time Complexity: O(n*log(n)). Space complexity: O(n).
int Solution(string s, int k)
{
    unordered_map<char,int>hm;
    for(auto c:s)
    {
        hm[c]++;
    }
    priority_queue<pair<char,int>, vector<pair<char,int>>, compare> q;
    for(auto ele:hm)
    {
        q.push(make_pair(ele.first,ele.second));
    }
    //perform k operation.
    while(k--)
    {
        pair<char,int>top = q.top();
        q.pop();
        if(top.second>1)
        {
            top.second = top.second-1;
            q.push(top);
        }
    }
    int res=0;
    while(!q.empty())
    {
        int x=q.top().second;
        res += x*x;
        q.pop();
    }
    hm.clear();
    return res;
}
main()
{
    string str;
    cout<<"Enter a string:"<<endl;
    cin>>str;
    int k;
    cout<<"Enter value of K: ";
    cin>>k;
    int result = Solution(str,k);
    cout<<"Minimum sum of squares of character counts in the given string after removing k characters is: "<<result<<endl;
}
