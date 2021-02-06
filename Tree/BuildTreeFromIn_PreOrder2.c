#include<iostream>
#include "BinaryTree.h"
using namespace std;
template <class T>
BinaryTree<T>* BuildTreeHelper(T *In, T *Pre, int inS, int inE, int preS, int preE)
{
    if(inS > inE)
        return NULL;
    T rootData = Pre[preS];
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
    BinaryTree<T> *root = new BinaryTree<T>(rootData);
    root->left = BuildTreeHelper(In,Pre,lInS,lInE,lPreS,lPreE);
    root->right = BuildTreeHelper(In,Pre,rInS,rInE,rPreS,rPreE);

    return root;
}
template <typename T>
BinaryTree<T>* BuildTree(T *In, T *Pre, int n)
{
    return BuildTreeHelper(In,Pre,0,n-1,0,n-1);
}
template <typename T>
void PreOrder(BinaryTree<T> *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"  ";
    PreOrder(root->left);
    PreOrder(root->right);
}
template <typename T>
void InOrder(BinaryTree<T> *root)
{
    if(root==NULL)
        return;
    InOrder(root->left);
    cout<<root->data<<"  ";
    InOrder(root->right);
}
template <typename T>
void PostOrder(BinaryTree<T> *root)
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
    BinaryTree<int> *root = BuildTree(In,Pre,n);
    PrintTree(root);
    cout<<endl;
    cout<<"Pre-Order Traversal of Tree is: ";
    PreOrder(root);
    cout<<endl;
    cout<<"In-Order Traversal of Tree is: ";
    InOrder(root);
    cout<<endl;
    cout<<"Post-Order Traversal of Tree is: ";
    PostOrder(root);
    cout<<endl;

    cout<<endl;
    cout<<endl;
    cout<<endl;


    char in[] = {'D','B','E','A','F','H','C','I','G','J'};
    char pre[] = {'A','B','D','E','C','F','H','G','I','J'};
    int n1=10;
    BinaryTree<char> *root1 = BuildTree(in,pre,n1);
    PrintTree(root1);
    cout<<endl;
    cout<<"Pre-Order Traversal of Tree is: ";
    PreOrder(root1);
    cout<<endl;
    cout<<"In-Order Traversal of Tree is: ";
    InOrder(root1);
    cout<<endl;
    cout<<"Post-Order Traversal of Tree is: ";
    PostOrder(root1);
}
