#include<iostream>
using namespace std;
#define max 5
class queueUsingStack
{
private:
    int rear=0,front=0;
    int top1=-1,top2=-1;
    int a[max],b[max];
public:
    void enqueue(int x)
    {
        if(top1!=max-1)
        {
            top1++;
            a[top1]=x;
            cout<<"\n"<<x<<" is inserted in queue.";
            rear=(rear+1)%max;
            cout<<"\nFront="<<front<<"\tRear="<<rear;
        }
        else
            cout<<"\nOverflow-  "<<x<<" is not inserted.";
    }
    void dequeue()
    {
        if(top2==-1){
        while(top1!=-1)
        {
            top2++;
            b[top2]=a[top1];
            top1--;
        }
        }
        cout<<"\nDeleted element is:"<<b[top2];
        top2--;
        front=(front+1)%max;
        cout<<"\nFront="<<front<<"\tRear="<<rear;
    }

};
main()
{
    queueUsingStack q;
    cout<<"Front=0\tRear=0";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.enqueue(7);
    q.dequeue();
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
}
