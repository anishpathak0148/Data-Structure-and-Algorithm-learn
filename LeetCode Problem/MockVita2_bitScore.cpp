//This is The Coding Area
#include<iostream>
#include<map>
#include<vector>
using namespace std;
int getlargestDigit(int n)
{
  int x=0;
  while(n>0)
  {
    int rmd = n%10;
    if(x<rmd)
      x=rmd;
    n = n/10;
  }
  return x;
}

int getSmallestDigit(int n)
{
  int x=n%10;
  n = n/10;
  while(n>0)
  {
    int rmd = n%10;
    if(x>rmd)
      x=rmd;
    n = n/10;
  }
  return x;
}

int findBitScore(int n)
{
  int l = getlargestDigit(n);
  int s = getSmallestDigit(n);
  int ans = 11*l + 7*s;
  if(ans>99)
  {
    ans = ans%100;
  }
  return ans;
}

int getMSB(int n)
{
  if(n<10)
    return n;
  //that is n is 2digit no..
  return n/10;
}

int main()
{
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  //now we find BitScore for each number...
  int *bit = new int[n];
  for(int i=0;i<n;i++)
  {
    bit[i] = findBitScore(arr[i]);
  }
  // now we make the pair..
  int count=0;
  //for odd position..
  map<int,vector<int>> m1;
  for(int i=0;i<n;i=i+2)
  {
    int temp = getMSB(bit[i]);
    m1[temp].push_back(bit[i]);
  }
  for(auto it = m1.begin();it!=m1.end();it++)
  {
    vector<int>v = it->second;
    if(v.size()>1)
    {
      if(v.size()==2)
        count += 1;
      else if(v.size()>2)
        count += 2;
    }
  }
  // for even position..
  map<int,vector<int>> m2;
  for(int i=1;i<n;i+=2)
  {
    int temp = getMSB(bit[i]);
    m2[temp].push_back(bit[i]);
  }
  for(auto it = m2.begin();it!=m2.end();it++)
  {
    vector<int>v = it->second;
    if(v.size()>1)
    {
      if(v.size()==2)
        count = count+1;
      else if(v.size()>2)
        count += 2;
    }
  }
  cout<<count;
}
