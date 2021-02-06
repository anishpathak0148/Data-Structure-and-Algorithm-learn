#include<iostream>
#include<cmath>
using namespace std;
main()
{
    int x1,y1,r1;//first circle center and radius.
    int x2,y2,r2;////second circle center and radius.
    cout<<"Enter first circle center and radius:";
    cin>>x1>>y1>>r1;
    cout<<"Enter first circle center and radius:";
    cin>>x2>>y2>>r2;

    //finding distance between center of both circle..
    double d;
    d = sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    cout<<"Distance is:"<<d;
    /*
    d_1	=	x=(d^2-r^2+R^2)/(2d)
    d_2	=	d-x=(d^2+r^2-R^2)/(2d).
    */
    double ans;
    if(d>= r1+r2)
        ans = 0;
    else
    {
        if(r1<r2)
        {

        }
        else
        {

        }
    }
}
