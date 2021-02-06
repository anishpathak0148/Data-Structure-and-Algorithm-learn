#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    char data;
    int D;//digonal distance.
    TreeNode *left;
    TreeNode *right;
};
TreeNode* CreateNode(char val)
{
    TreeNode *temp = new TreeNode;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void DigonalTraverse(TreeNode *root)
{
    if(root==NULL)
        return;
    queue<TreeNode*>q;
    map<int,vector<char>>m;
    int d=0;
    root->D=d;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *temp=q.front();
        d=temp->D;
        m[d].push_back(temp->data);
        if(temp->left)
        {
            temp->left->D=d+1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->D=d;
            q.push(temp->right);
        }
        q.pop();
    }

    for(auto i=m.begin();i!=m.end();i++)
    {
        vector<char>::iterator it=i->second.begin();
        while(it!=i->second.end())
        {
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
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
    TreeNode *root=CreateNode('A');
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
    cout<<endl<<endl;
    cout<<"Diagonal Traverse of Tree is:"<<endl;
    DigonalTraverse(root);
}
