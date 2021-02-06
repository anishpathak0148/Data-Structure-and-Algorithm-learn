#include<iostream>
using namespace std;
struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};
BSTNode* CreateNode(int x)
{
    BSTNode *temp=new BSTNode;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
BSTNode *root=NULL;

BSTNode* InsertionInBST(BSTNode *root, int Data)
{
    if(root==NULL)
    {
        root=CreateNode(Data);
        return root;
    }
    else if(Data<=root->data)
    {
        root->left = InsertionInBST(root->left,Data);
    }
    else
    {
        root->right = InsertionInBST(root->right,Data);
    }
    return root;
}

void InOrderTraverse(BSTNode *root)
{
    if(root==NULL)
        return;
    InOrderTraverse(root->left);
    cout<<root->data<<"  ";
    InOrderTraverse(root->right);
}

void PreOrderTraverse(BSTNode *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"  ";
    PreOrderTraverse(root->left);
    PreOrderTraverse(root->right);
}

void PostOrderTraverse(BSTNode *root)
{
    if(root==NULL)
        return;
    PostOrderTraverse(root->left);
    PostOrderTraverse(root->right);
    cout<<root->data<<"  ";
}
main()
{
    root = InsertionInBST(root,15);
    root = InsertionInBST(root,10);
    root = InsertionInBST(root,20);
    root = InsertionInBST(root,25);
    root = InsertionInBST(root,8);
    root = InsertionInBST(root,12);
    root = InsertionInBST(root,7);

    cout<<"InOrder Traverse of BST is :"<<endl;
    InOrderTraverse(root);

    cout<<"\n\nPreOrder Traverse of BST is :"<<endl;
    PreOrderTraverse(root);

    cout<<"\n\n0PostOrder Traverse of BST is :"<<endl;
    PostOrderTraverse(root);
}

