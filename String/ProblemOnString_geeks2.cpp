/*

Maximum and minimum sums from two numbers with digit replacements
Last Updated: 27-09-2020
Given two positive numbers calculate the minimum and maximum possible sums of two numbers.
We are allowed to replace digit 5 with digit 6 and vice versa in either or both the given numbers.

Examples :

Input  : x1 = 645 x2 = 666
Output : Minimum Sum: 1100 (545 + 555)
         Maximum Sum: 1312 (646 + 666)

Input: x1 = 5466 x2 = 4555
Output: Minimum sum: 10010
        Maximum Sum: 11132

*/

#include<iostream>
using namespace std;
main()
{
    string s1,s2;
    cout<<"Enter two numbers: ";
    cin>>s1>>s2;
    string maxN1="",maxN2="",minN1="",minN2="";
    for(int i=0;i<s1.length();i++)
    {
        if(s1[i]=='6')
            minN1 += '5';
        else
            minN1 += s1[i];
        if(s1[i]=='5')
            maxN1 += '6';
        else
            maxN1 += s1[i];
    }
    for(int i=0;i<s2.length();i++)
    {
        if(s2[i]=='6')
            minN2 += '5';
        else
            minN2 += s2[i];
        if(s2[i]=='5')
            maxN2 += '6';
        else
            maxN2 += s2[i];
    }
    int minSum = stoi(minN1) + stoi(minN2);
    int maxSum = stoi(maxN1) + stoi(maxN2);

    cout<<"Maximum Sum is: "<<maxSum<<endl;
    cout<<"Minimum Sum is: "<<minSum<<endl;
}
