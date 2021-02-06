#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode
{
public:
    T data;
    int Hd;
    TreeNode *left;
    TreeNode *right;
};
template<typename T>
TreeNode* CreateNode(T key)
{
    TreeNode<T> *temp=new TreeNode;
    temp->data=key;
    temp->left=nullptr;
    temp->right=nullptr;
    return temp;
}
TreeNode *root=nullptr;

void TopView(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    queue<TreeNode*>q;
    map<int,T>m;
    int hd=0;
    root->Hd=hd;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *temp = q.front();
        hd=temp->Hd;
        if(m.count(hd)==0)
        {
            m[hd]=temp->data;
        }
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
        cout<<i->second<<" ";
    }
}

void InOrderTraverse(TreeNode *root)
{
    if(root==NULL)
        return;
    InOrderTraverse(root->left);
    cout<<root->data<<"  ";
    InOrderTraverse(root->right);
}
main()
{
    TreeNode<int> *root=CreateNode(1);
    root->left = CreateNode(2);
    root->right = CreateNode(3);
    root->left->left = CreateNode(4);
    root->left->right = CreateNode(5);
    root->right->left = CreateNode(6);
    root->right->right = CreateNode(7);
    root->left->left->left = CreateNode(8);
    root->right->left->left = CreateNode(9);
    root->right->left->right = CreateNode(10);
    root->right->left->right->right = CreateNode(11);
    cout<<"In-order Travesal of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Right View of Tree is:"<<endl;
    TopView(root);
}
