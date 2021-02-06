#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node* CreateNode(int x)
{
    Node *temp=new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node *root=NULL;

void LeftView(Node *root)
{
    if(root==nullptr)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        int queueCount=q.size();
        while(count>0){
            Node *temp=q.front();
            q.pop();

            if(count==queueCount)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            count--;
        }

    }
}

void InOrderTraverse(Node *root)
{
    if(root==NULL)
        return;
    InOrderTraverse(root->left);
    cout<<root->data<<"  ";
    InOrderTraverse(root->right);
}
main()
{
    Node *root = CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);
    root->left->left->left = CreateNode(8);
    root->right->left->left = CreateNode(9);
    root->right->left->right = CreateNode(10);
    root->right->left->right->right = CreateNode(11);
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Left View of Tree is:"<<endl;
    LeftView(root);

    cout<<endl<<endl;
    root=NULL;

    root = CreateNode(1);
    root->left=CreateNode(8);
    root->right=CreateNode(12);
    root->left->left=CreateNode(6);
    root->left->right=CreateNode(9);
    root->right->left=CreateNode(11);
    root->right->right=CreateNode(15);
    root->right->right->left=CreateNode(14);
    root->right->right->right=CreateNode(16);
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Left View of Tree is:"<<endl;
    LeftView(root);
}
