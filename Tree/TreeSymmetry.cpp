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
bool Symmetry_helper(BNode *root1, BNode *root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if((root1 && root2==NULL)||(root1==NULL && root2))
    {
        return false;
    }
    if(root1->data==root2->data){
        bool lt = Symmetry_helper(root1->left,root2->right);
        bool rt = Symmetry_helper(root1->right,root2->left);
        if(lt&&rt)
        {
            return true;
        }
        else
        {
            false;
        }
    }
    return false;
}
string isSymmetric(BNode *root)
{
    return (Symmetry_helper(root,root)?"YES":"NO");
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

    cout<<"Is this B.Tree is Symmetric: "<<isSymmetric(root);
}
