#include<iostream>
using namespace std;
int hammingDistance(int x, int y) {
    //To calculate hamming distance first perform XOR operation then no of set bits in the resultant number..
    // is called Hamming distance.
    int n = x^y;
    int count=0;
    while(n!=0)
    {
        if(n & 1 ==1)
            count++;
        n = n>>1;
    }
    return count;
}
main()
{
    int a,b;
    cout<<"Enter two number to find the Hamming distance b/w them: ";
    cin>>a>>b;
    cout<<"Hamming Distance between "<<a<<" and "<<b<<" is: "<<hammingDistance(a,b);
}
