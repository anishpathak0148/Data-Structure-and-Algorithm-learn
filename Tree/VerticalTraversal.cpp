#include<bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    int Hd;
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
void VerticalTraverse(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    map<int,vector<char>>m;
    int hd=0;
    root->Hd=hd;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        hd=temp->Hd;
        m[hd].push_back(temp->data);
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
    for(auto i=m.begin();i!=m.end();i++)
    {
        for(int j=0;j<i->second.size();j++)
        {
            cout<<i->second[j]<<" ";
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
    root->right->right->left = CreateNode('M');
    root->right->right->right = CreateNode('L');
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Vertical Traverse of Tree is:"<<endl;
    VerticalTraverse(root);
}
