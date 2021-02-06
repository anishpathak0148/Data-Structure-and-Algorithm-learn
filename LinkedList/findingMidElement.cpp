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
//Basic Naive approach with O(n) complexity in two pass.
List* MiddleNode(List * head)
{
    int count=0,mid;
    List *ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    mid=count/2;
    for(int i=1;i<=mid;i++)
        ptr=ptr->next;

    return ptr;
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
    //mid = MiddleNode(head);
    mid = MidNode(head);
    cout<<"\nMiddle Node is : "<<mid->info;
}
