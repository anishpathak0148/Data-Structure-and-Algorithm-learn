#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node * left;
    Node* right;
    int hd;
    int data;
};
Node* CreateNode(int x)
{
    Node *temp = new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
/*
Node* newnode(int key)
{
    Node* node=new Node();
    node->left = node->right = NULL;
    node->data=key;
    return node;
}
*/
void topview(Node* root)
{
    if(root==NULL)
       return;
     queue<Node*>q;
     map<int,int> m;
     int hd=0;
     root->hd=hd;
    q.push(root);

    cout<< "The top view of the tree is : \n";

    while(q.size())
    {
        hd=root->hd;
        if(m.count(hd)==0)
        m[hd]=root->data;
        if(root->left)
        {
            root->left->hd=hd-1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd=hd+1;
            q.push(root->right);
        }
        q.pop();
        root=q.front();

    }



     for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }

}


int main()
{
/*
   Node* root = newnode(1);
   root->left=newnode(8);
root->right=newnode(12);
root->left->left=newnode(6);
root->left->right=newnode(9);
root->right->left=newnode(11);
root->right->right=newnode(15);
root->right->right->left=newnode(14);
root->right->right->right=newnode(16);
*/
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
    cout<<"Following are nodes in top view of Binary Tree\n";
    topview(root);
    return 0;
}
