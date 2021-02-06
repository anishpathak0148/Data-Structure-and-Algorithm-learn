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


//Advanced approach with O(n) complexity in single pass.
List* MidNode(List *head)
{
    List *slow,*fast;
    slow=head,fast=head;
    while(fast!=NULL)
    {
        fast=fast->next;

        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

    }
    return slow;
}
List* ReverseAfterMid(List *head,List *mid)
{
    List *curr,*prev,*Next;
    prev=NULL;
    curr=mid->next;
    while(curr!=NULL)
    {
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    mid->next=prev;
    return head;
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
    struct List *mid;
    mid = MidNode(head);
    cout<<"\nMiddle Node is : "<<mid->info;
    cout<<"\nReverse after mid Node"<<endl;
    head=ReverseAfterMid(head,mid);
    display();
}

