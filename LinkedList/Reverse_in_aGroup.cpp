#include<iostream>
using namespace std;
struct List
{
    int info;
    struct List *next;
};
List *head=NULL;
List *tail=NULL;
List* CreateNode()
{
    List *Node;
    Node = new List;
    return Node;
}
void insertNode()
{
    List *temp;
    temp=CreateNode();
    cout<<"Enter Node data:";
    cin>>temp->info;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
    }
}
void display()
{
    if(head==NULL)
        cout<<"\nList is Empty.";
    else
    {
        List *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<"->";
            ptr=ptr->next;
        }
    }
}

List* ReverseGroup(List* head,int k)
{
    int n=0,t=k;
    List *prev,*curr,*Next,*ptr;
    ptr=curr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        n++;
    }
    ptr=head;
    while(t>0)
    {
        ptr=ptr->next;
        t--;
    }
    t=k;
    prev=ptr;
    for(int i=1;i<=n/k;i++)
    {
        while(t>0)
        {
           Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
            t--;
        }
        head=prev;
    }


    prev=NULL;
    while(curr!=NULL)
    {
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    ptr=prev;
}

main()
{
    int n;
    cout<<"Enter a no:";
    cin>>n;
    cout<<"\nEnter "<<n<<" node:"<<endl;
    for(int i=1;i<=n;i++)
        insertNode();
    cout<<"\nList is:"<<endl;
    display();

    cout<<"\nReverse after mid Node"<<endl;
    head=ReverseAfterMid(head,mid);
    display();
}
