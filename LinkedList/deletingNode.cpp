#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node*next;
}*head=NULL,*tail=NULL;
void InsertAtLast(int x)
{
    Node* temp=new Node;
    temp->data=x;
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

int deleteNode(int n)
{
    if(head==NULL)
        return -1;
    else
    {
        if(n==1)
        {
            Node *q=head;
            head=head->next;
            delete q;
            return q->data;
       }
        else
        {
            Node* ptr=head;

            for(int i=1;i<n-1;i++)
            {
                ptr=ptr->next;
            }
            Node* x=ptr->next;
            ptr->next=ptr->next->next;
            //int t=x->data;
            x->next=NULL;
            delete x;
            return x->data;
        }
    }
}
void deleteMidNode()
{
    if(head==NULL)
    {
        cout<<"List is Empty.";
    }
    else if(head->next==NULL)
    {
        Node *temp=head;
        head=NULL;
        cout<<"Deleted Node is:"<<temp->data<<endl;
        delete temp;
    }
    else
    {
        Node *slow=head;
        Node *fast=head;
        while(fast && fast->next)
        {
            fast=fast->next;
            fast=fast->next;
            if(fast)
                slow=slow->next;

        }
        int t=slow->data;
        slow->data=slow->next->data;
        Node *p = slow->next;
        slow->next=p->next;
        delete p;
        cout<<"\nDeleted Node is"<<t<<endl;
    }
}

void print()
{
    Node* temp=head;
    cout<<"print list"<<" "<<endl;
    while(temp!=NULL)
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;


}
int main()
{
    int x;
    cout<<"how many numbers:";
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"enter the node"<<i+1<<" :";
        cin>>x;
        InsertAtLast(x);
    }
    print();
    cout<<"\nEnter the position of node to delete:";
    int pos;
    cin>>pos;
    if(pos<1 || pos>n)
        cout<<"Invalid Input."<<endl;
    else{
        int res=deleteNode(pos);
        cout<<"\nDeleted node: "<<res<<endl;
        print();
    }
    deleteMidNode();
    print();
}

