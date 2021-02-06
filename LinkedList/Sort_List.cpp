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

List* SplitList(List *start, List **left, List **right)
{
    List *slow,*fast;
    slow=start;
    fast=start;
    while(fast)
    {
        fast=fast->next;
        if(fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }

    *left=start;
    *right=slow->next;
    slow->next=NULL;
}

List* SortedMerge(List *a, List *b)
{
    List *result=NULL;
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return a;
    }
    if(a->data <= b->data)
    {
        result=a;
        result->next= SortedMerge(a->next,b);
    }
    else
    {
        result=b;
        result->next= SortedMerge(a,b->next);
    }
    return result;
}
void MergeSortList(List** head)
{
    List *start,*a,*b;
    start=*head;
    if(start==NULL || start->next==NULL)
    {
        return;
    }
    //split the list into two sublist a and b.
    SplitList(start,&a,&b);
    //Recursively sort the sublist.
    MergeSortList(&a);
    MergeSortList(&b);
    //merge the two sorted sublist.
    *head = SortedMerge(a,b);
    return;
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

    cout<<"\nAfter Sorting List is :"<<endl;
    MergeSortList(&head);
    display(head);
}
