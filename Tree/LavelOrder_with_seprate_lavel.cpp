#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    Node *left;
    Node *right;
};
Node* CreateNode(char key)
{
    Node *temp = new Node;
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void LavelOrderSeprate(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        while(count>0)
        {
            Node *temp=q.front();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
            count--;
        }
        cout<<endl;
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
    Node *root=CreateNode('A');
    root->left = CreateNode('B');
    root->right = CreateNode('C');
    root->left->left = CreateNode('D');
    root->left->right = CreateNode('E');
    root->right->left = CreateNode('F');
    root->right->right = CreateNode('G');
    root->left->left->left = CreateNode('H');
    root->left->left->right = CreateNode('I');
    root->right->left->left = CreateNode('J');
    root->right->left->right = CreateNode('K');
    root->right->right->left = CreateNode('L');
    root->right->right->right = CreateNode('M');
    cout<<"In-order Traverse of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Level by level Traverse of Tree is:"<<endl;
    LavelOrderSeprate(root);
}
