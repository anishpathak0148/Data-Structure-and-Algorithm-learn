#include<iostream>
using namespace std;

struct BTree
{
    int data;
    BTree *left;
    BTree *right;
    BTree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

BTree* BuildTreeHelper(int *In, int *Pre, int inS, int inE, int preS, int preE)
{
    if(inS > inE)
        return NULL;
    int rootData = Pre[preS];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++)
    {
        if(In[i]==rootData)
        {
            rootIndex = i;
            break;
        }
    }
    //For left Sub-tree
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPreS = preS+1;
    int lPreE = lInE-lInS+lPreS;        // lPreE - lPreS = lInE - lInS
    //For right Sub-tree;
    int rInS = rootIndex+1;
    int rInE = inE;
    int rPreS = lPreE+1;
    int rPreE = preE;
    //Now we call recursively for left subtree and right subtree;
    BTree *root = new BTree(rootData);
    root->left = BuildTreeHelper(In,Pre,lInS,lInE,lPreS,lPreE);
    root->right = BuildTreeHelper(In,Pre,rInS,rInE,rPreS,rPreE);

    return root;
}
BTree* BuildTree(int *In, int *Pre, int n)
{
    return BuildTreeHelper(In,Pre,0,n-1,0,n-1);
}
void PreOrder(BTree *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"  ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BTree *root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    cout<<root->data<<"  ";
    InOrder(root->right);
}
void PostOrder(BTree *root)
{
    if(root==NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<"  ";
}
main()
{
    int In[] = {4,2,5,1,8,6,9,3,7};
    int Pre[] = {1,2,4,5,3,6,8,9,7};
    int n=9;
    BTree *root = BuildTree(In,Pre,n);
    cout<<"Pre-Order Traversal of Tree is: ";
    PreOrder(root);
    cout<<endl;
    cout<<"In-Order Traversal of Tree is: ";
    InOrder(root);
    cout<<endl;
    cout<<"Post-Order Traversal of Tree is: ";
    PostOrder(root);
    cout<<endl;
}

