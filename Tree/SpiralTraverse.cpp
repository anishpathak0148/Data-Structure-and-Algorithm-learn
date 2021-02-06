#include<bits/stdc++.h>
using namespace std;
struct BNode
{
    char data;
    BNode *left;
    BNode *right;
};
BNode* CreateNode(char Data)
{
    BNode *temp=new BNode;
    temp->data=Data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int height(BNode *root)
{
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh>rh)
    {
        return lh+1;
    }
    else
    {
        return rh+1;
    }
}
void Spiral(BNode *root, int lavel,bool ltr)
{
    if(root==NULL)
        return;
    if(lavel==1)
    {
        cout<<root->data<<" ";
    }
    else if(lavel>1)
    {
        if(ltr)
        {
            Spiral(root->left,lavel-1,ltr);
            Spiral(root->right,lavel-1,ltr);
        }
        else
        {
            Spiral(root->right,lavel-1,ltr);
            Spiral(root->left,lavel-1,ltr);
        }
    }
}
void SpiralTraverse(BNode *root)
{
    bool ltr=true;
    int h=height(root);
    for(int i=1;i<=h;i++)
    {
        Spiral(root,i,ltr);
        ltr=!ltr;
        cout<<endl;
    }
}

void InOrderTraverse(BNode *root)
{
    if(root==NULL)
        return;
    InOrderTraverse(root->left);
    cout<<root->data<<"  ";
    InOrderTraverse(root->right);
}
main()
{
    BNode *root=CreateNode('A');
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
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;

    cout<<"Spiral Traverse of B.Tree is:"<<endl;
    SpiralTraverse(root);
}

