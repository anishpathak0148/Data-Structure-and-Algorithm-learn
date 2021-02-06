#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class StackUsingLink
{
    Node *top=NULL;
public:
    void push(int x)
    {
        Node *temp=new Node(x);
        if(top==NULL)
        {
            top=temp;
        }
        else
        {
            temp->next=top;
            top=temp;
        }
    }
    void pop()
    {
        if(top==NULL)
            cout<<"\nUnderflow...Stack is Empty.";
        else
        {
            Node *temp=top;
            cout<<"\nPop element is:"<<top->data;
            top=top->next;
            delete(temp);
        }
    }
    int peek()
    {
        if(top==NULL)
            return -1;
        else
            return top->data;
    }
    void display()
    {
        if(top==NULL)
            cout<<"\nStack is empty.";
        else
        {
            cout<<"\nElement in stack is:..."<<endl;
            Node *temp=top;
            while(temp)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
main()
{
    StackUsingLink s;
    s.pop();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();
    s.pop();
    s.pop();
    s.display();
    s.push(60);
    s.push(70);
    s.push(80);
    s.pop();
    s.push(90);
    s.display();
}
