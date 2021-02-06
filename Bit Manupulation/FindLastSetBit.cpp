#include<iostream>
using namespace std;
void findLastSet_bit(int n)
{
    int index=0;
    while(n>0)
    {
        index++;
        n=n>>1;   //it means n is divided by 2.
    }
    index--;
    cout<<"Index of last set bit is:"<<index<<endl;
    int result=1<<index;
    cout<<"Power(2, "<<index<<") is: "<<result;
}
main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    findLastSet_bit(n);
}
