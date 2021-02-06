#include<iostream>
#include<string>
using namespace std;
//Note: Same logic for..
/*
Convert Binary Number in a Linked List to Integer
Easy

780

49

Add to List

Share
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1.
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
*/
//Using Binary Representation.
int getDecimalValue(string num)
{
    int sum = 0;
    for(int i=0;i<num.length();i++)
    {
        int x = num[i] - '0';
        sum = sum*2 + x;
    }
    return sum;
}
//Using Bit Manipulation.
int getDecimal(string num)
{
    int sum=0;
    for(int i=0;i<num.length();i++)
    {
        int x = num[i]-'0';
        sum = (sum<<1) | x;
    }
    return sum;
}
main()
{
    string input;
    cout<<"Enter input binary string is: ";
    cin>>input;
    cout<<"Decimal value of given binary string is: "<<getDecimalValue(input)<<endl;
    cout<<"Decimal value of given binary string is: "<<getDecimal(input)<<endl;
}
