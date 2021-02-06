#include<iostream>
using namespace std;
struct CList
{
    int data;
    CList *next;
};
CList *head=NULL;
CList *tail=NULL;
void insertNode(int Data, int pos)
{
    CList *temp = new CList;
    temp->data=Data;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp->next=head;
    }
    else
    {
        if(pos==0)  //pos=0 means head node.
        {
            temp->next=head;
            tail->next=temp;
            head=temp;
        }
        else if(pos==1) //pos=1 means last node.
        {
            tail->next=temp;
            temp->next=head;
            tail=tail->next;
        }
    }
}
void traverse()
{
    CList *ptr = head;
    do
    {
        cout<<ptr->data<<" -> ";
        if(ptr->next==head)
            cout<<ptr->next->data;
        ptr=ptr->next;
    }while(ptr!=head);
}
main()
{
    int n,ch,x;
    cout<<"Enter how many data do you want to insert: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter data and position to insert(0 for Head / 1 for Tail):";
        cin>>x>>ch;
        insertNode(x,ch);
    }
    cout<<"\n Circular List is: "<<endl;
    traverse();
}
