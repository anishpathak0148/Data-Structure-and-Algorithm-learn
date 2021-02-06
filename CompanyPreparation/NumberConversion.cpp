#include<iostream>
using namespace std;
void decimal_to_binary(int decimal)
{
    int binary=0,i=1;
    while(decimal!=0)
    {
        binary += (decimal%2)*i;
        decimal /= 2;
        i=i*10;
    }
    cout<<"Binary form is: "<<binary<<endl;
}

void decimal_to_binaryForBigNum(int decimal)
{
    string binary="";
    while(decimal!=0)
    {
        binary = to_string(decimal%2) + binary;
        decimal /= 2;
    }
    cout<<"Binary form is: "<<binary<<endl;
}
void decimal_to_Octal(int decimal)
{
    int octal=0,i=1;
    while(decimal!=0)
    {
        octal += (decimal%8)*i;
        decimal /= 8;
        i=i*10;
    }
    cout<<"Octal form is: "<<octal<<endl;
}

main()
{
    int num;
    cout<<"Enter a number in Decimal:";
    cin>>num;
    decimal_to_binary(num);
    decimal_to_binaryForBigNum(num);
    decimal_to_Octal(num);
}
