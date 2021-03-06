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
    int lh=height(root->left);
    int rh=height(root->right);
    return ((lh>rh)?lh+1:rh+1);
}
int diameter(BNode *root)
{
    if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    int ldia=diameter(root->left);
    int rdia=diameter(root->right);

    return max(lh+rh+1 , max(ldia,rdia));
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

    int h=height(root);
    cout<<"Height of B.Tree is: "<<h<<endl<<endl;

    int d=diameter(root);
    cout<<"Diameter of B.Tree is: "<<d;
}

