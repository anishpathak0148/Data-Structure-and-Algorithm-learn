#include<iostream>
using namespace std;
struct DList
{
    int data;
    DList *prev;
    DList *next;
};
DList* CreateNode(int x)
{
    DList *temp = new DList;
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
DList *head = NULL;
DList *tail = NULL;
void insertAtBeg(int Data)
{
    DList *temp = CreateNode(Data);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertAtLast(int Data)
{
    DList *temp=CreateNode(Data);
    if(head==NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = tail->next;
    }
}
void deleteNode(int pos)
{
    if(head==NULL)
    {
        cout<<"List is empty->Underflow...."<<endl;
    }
    else
    {
        if(pos==1)  //pos=1 mean delete head node.
        {
            DList *t = head;
            head = head->next;
            head->prev=NULL;
            t->next=NULL;
            cout<<"Deleted Node is: "<<t->data;
            delete t;
        }
        else
        {
            DList *ptr=head;
            for(int i=1;i<pos;i++)
            {
                ptr=ptr->next;
            }
            ptr->next->prev=ptr->prev;
            ptr->prev->next=ptr->next;
            ptr->next=NULL;
            ptr->prev=NULL;
            cout<<"Deleted Node is: "<<ptr->data;
            delete ptr;
        }
    }
}

void traverse()
{
    DList *ptr=head;
    cout<<"\n Forward traverse of Doubly list is :"<<endl;
    while(ptr!=NULL)
    {
        if(ptr==head)
            cout<<"<- "<<ptr->data<<" <-> ";
        else if(ptr==tail)
            cout<<ptr->data<<"->";
        else
            cout<<ptr->data<<" <-> ";
        ptr=ptr->next;
    }
}
void reverseTraverse()
{
    cout<<"\n\n Backward traverse of Doubly list is :"<<endl;
    DList *ptr=tail;
    while(ptr!=NULL)
    {
        if(ptr==tail)
            cout<<"<- "<<ptr->data<<" <-> ";
        else if(ptr==head)
            cout<<ptr->data<<"->";
        else
            cout<<ptr->data<<" <-> ";
        ptr=ptr->prev;
    }
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
        if(ch==0)
        {
            insertAtBeg(x);
        }
        else if(ch==1)
        {
            insertAtLast(x);
        }
        else
        {
            cout<<"Invalid input";
            break;
        }
    }

    traverse();

    reverseTraverse();
    int pos;
    cout<<"\n\nEnter position to delete node(1 for Head):";
    cin>>pos;
    deleteNode(pos);
    traverse();
}
