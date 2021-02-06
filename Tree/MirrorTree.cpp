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
void MirrorTree(BNode *root)
{
    if(root==NULL)
    {
        return;
    }
    MirrorTree(root->left);
    MirrorTree(root->right);
    BNode *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
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
    root->right->right->left = CreateNode('M');
    root->right->right->right = CreateNode('L');
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;

    MirrorTree(root);
    cout<<"In-order traverse of Mirror tree is:"<<endl;
    InOrderTraverse(root);
}

