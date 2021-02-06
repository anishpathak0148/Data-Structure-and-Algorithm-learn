#include<iostream>
using namespace std;
class List
{
public:
    int data;
    List *next;
};
List* CreateNode(int x)
{
    List *node = new List;
    node->data=x;
    node->next=NULL;
    return node;
}
List *head = NULL;
List *tail = NULL;

void InsertNode()
{
    int data;
    cout<<"Enter Node data:";
    cin>>data;
    List *temp=CreateNode(data);
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
void display(List* head)
{
    if(head==NULL)
        cout<<"\nList is Empty.";
    else
    {
        List *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
    }
}
List* reverseList(List* head)
{
    List *prev,*curr,*Next;
    prev=NULL;
    curr=head;
    while(curr)
    {
        Next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=Next;
    }
    head=prev;
    return head;
}
main()
{
    int n;
    cout<<"Enter a no:";
    cin>>n;
    cout<<"\nEnter "<<n<<" node:"<<endl;
    for(int i=1;i<=n;i++)
        InsertNode();
    cout<<"\nList is:"<<endl;
    display(head);

    cout<<"\nReverse List is :"<<endl;
    List* head1=reverseList(head);
    display(head1);
}

