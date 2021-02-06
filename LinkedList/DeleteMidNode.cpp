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
void deleteMidNode(Node *head)
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
        Node* temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        int mid=(count+1)/2;
        temp=head;
        for(int i=1;i<mid-1;i++)
        {
            temp=temp->next;
        }
        Node *p=temp->next;
        temp->next=p->next;
        cout<<"\nDeleted Node is"<<p->data<<endl;
        p->next=NULL;
        delete p;

    }
}
//Advanced approach...
Node* deleteMid(Node*head) {
    if(head==NULL)
        return head;
    else if(head->next==NULL)
    {
        cout<<"\nDeleted Node is: "<<head->data<<endl;
        delete head;
        return NULL;
    }

    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next;
        fast = fast->next;
        if(fast){
            prev = slow;
            slow=slow->next;
        }
    }
    Node *p = slow;
    if(prev!=NULL)
        prev->next=p->next;
    else
        head = p->next;
    delete p;
    cout<<"\nDeleted Node is: "<<p->data<<endl;
    delete slow;
    delete fast;
    return head;
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
    //deleteMidNode(head);
    head = deleteMid(head);
    print();
}

