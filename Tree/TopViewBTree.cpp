#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int Hd;
    Node *left;
    Node *right;
};

Node* CreateNode(int x)
{
    Node *temp = new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

Node *root=NULL;

void TopView(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q;
    map<int,int>m;
    int hd=0;
    root->Hd=hd;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        hd=temp->Hd;
        if(m.count(hd)==0)
        {
            m[hd]=temp->data;
        }
        if(temp->left)
        {
            temp->left->Hd=hd-1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->Hd=hd+1;
            q.push(temp->right);
        }

        q.pop();
    }
    /*
    map<int,int>::iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->second<<" ";
        it++;
    }
    */
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
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
    cout<<"Top View of Tree is:"<<endl;
    TopView(root);

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
    cout<<"Top View of Tree is:"<<endl;
    TopView(root);
}
