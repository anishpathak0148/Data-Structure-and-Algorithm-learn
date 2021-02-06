#include<iostream>
using namespace std;
class queueDemo
{
private:
    int front,rear,n;
    int *a;
public:
    queueDemo(int capacity)
    {
        front=rear=0;
        n = capacity;
        a = new int[n];
    }
    bool is_Full()
    {
        if(rear==n)
            return true;
        else
            return false;

    }
    bool is_Empty()
    {
        if(front==-1)
            return true;
        else
            return false;
    }
    void enqueue(int x)
    {
        if(!is_Full())
        {
            a[rear]=x;
            rear++;
            cout<<"\n"<<x<<" is inserted in queue.";
            cout<<"\nFront="<<front<<"\tRear="<<rear;
        }
        else
            cout<<"\nOverflow.";
    }
    void dequeue()
    {
        if(!is_Empty())
        {
            cout<<"\nDeleted element is :"<<a[front];
            front++;
            cout<<"\nFront="<<front<<"\tRear="<<rear;
        }
        else
            cout<<"\nUnderflow";
    }
};
main()
{
    queueDemo q(5);
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
