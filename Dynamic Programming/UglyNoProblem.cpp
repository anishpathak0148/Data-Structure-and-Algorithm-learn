/*
Problem:
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:
1<=n<=1690
*/
#include<iostream>
using namespace std;
class UglyNo {
public:
    bool isUgly(int n)  //this check weather a number is Ugly no or not.
    {
        if(n==1)
            return true;
        if(n%2==0)
            return isUgly(n/2);
        else if(n%3==0)
            return isUgly(n/3);
        else if(n%5==0)
            return isUgly(n/5);

        return false;
    }
    int nthUglyNumUsingRec(int n) {
        int count=0;
        int i=1,res=0;
        while(count<n)
        {
            if(isUgly(i))
            {
                res = i;
                //cout<<res<<"\t";
                count++;
            }
            i++;
        }
        //cout<<endl;
        return res;
    }
    //Since the above solution is not time efficient so now we can solve this problem by using DP.
    int nthUglyNumUsingDp(int n) {

        unsigned ugly[n]; // To store ugly numbers
        unsigned i2 = 0, i3 = 0, i5 = 0;
        unsigned next_multiple_of_2 = 2;
        unsigned next_multiple_of_3 = 3;
        unsigned next_multiple_of_5 = 5;
        unsigned next_ugly_no = 1;

        ugly[0] = 1;
        for (int i=1; i<n; i++)
        {
           next_ugly_no = min(next_multiple_of_2,
                               min(next_multiple_of_3,
                                   next_multiple_of_5));
           ugly[i] = next_ugly_no;
           if (next_ugly_no == next_multiple_of_2)
           {
               i2 = i2+1;
               next_multiple_of_2 = ugly[i2]*2;
           }
           if (next_ugly_no == next_multiple_of_3)
           {
               i3 = i3+1;
               next_multiple_of_3 = ugly[i3]*3;
           }
           if (next_ugly_no == next_multiple_of_5)
           {
               i5 = i5+1;
               next_multiple_of_5 = ugly[i5]*5;
           }
           //cout<<next_ugly_no<<"\t";
        } /*End of for loop (i=1; i<n; i++) */
        //cout<<endl;
        return next_ugly_no;
    }
};
main()
{
    int n;
    cout<<"Enter the number to find nth Ugly number:";
    cin>>n;
    UglyNo u;
    cout<<n<<"th Ugly number using DP is: "<<u.nthUglyNumUsingDp(n)<<endl;
    cout<<n<<"th Ugly number using Recursion is: "<<u.nthUglyNumUsingRec(n)<<endl;
}
