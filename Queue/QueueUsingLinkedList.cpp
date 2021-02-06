#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class QueueUsingLink
{
    Node *front=NULL;
    Node *rear=NULL;
public:
    void enqueue(int x)
    {
        Node *temp=new Node;
        temp->data=x;
        temp->next=NULL;
        if(front==NULL && rear==NULL)
        {
            front=temp;
            rear=temp;
        }
        else
        {
            rear->next=temp;
            rear=rear->next;
        }
    }
    void dequeue()
    {
        if(front==NULL)
            cout<<"\nUnderflow--Queue is empty.";
        else
        {
            Node *temp=front;
            cout<<"\nDeleted element is: "<<front->data;
            front=front->next;
            delete(temp);
            temp = nullptr;//always assign temp to null. because it is free from memory but although it stored the address.
            //this is called Dangling pointer.
            //cout<<"\n"<<temp->data<<endl;
        }
    }
    void display()
    {
        if(front==NULL)
            cout<<"\nQueue is Empty.";
        else
        {
            Node *temp=front;
            cout<<"\nElement in Queue is:..."<<endl;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
main()
{
    QueueUsingLink q;
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();

}
