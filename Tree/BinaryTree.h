#include<iostream>
using namespace std;
template <class T>
class BinaryTree
{
public:
    T data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(T data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

template <class BinaryTree>
void PrintTree(BinaryTree *root)
{
    // Here we use Pre-order traversal.
    if(root==NULL)
        return;
    cout<<root->data<<": ";
    if(root->left)
        cout<<"L- "<<root->left->data<<" ";
    if(root->right)
        cout<<"R- "<<root->right->data<<" ";
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}

