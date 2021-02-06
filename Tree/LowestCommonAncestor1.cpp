#include<iostream>
#include<stack>
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
stack<int> search_node(BSTNode *root,int Data,stack<int>s)
{

    if(root==NULL)
        return s;
    else if(root->data==Data)
    {
        s.push(root->data);
        return s;
    }
    else if(Data<=root->data)
    {
        s.push(root->data);
        search_node(root->left,Data,s);
    }
    else
    {
        s.push(root->data);
        search_node(root->right,Data,s);
    }
}
void LowestCommonAncestor(BSTNode *root, int node1, int node2)
{
    stack<int>s1;
    stack<int>s2;
    search_node(root,node1,s1);
    search_node(root,node2,s2);
    int n1=s1.size();
    int n2=s2.size();
    if(n1>n2)
    {
        while(n1-n2)
        {
            s1.pop();
            n1--;
        }
    }
    else
    {
        while(n2-n1)
        {
            s2.pop();
            n2--;
        }
    }

    while(!s1.empty())
    {
        if(s1.top()==s2.top())
        {
            cout<<"Lowest Common Ancestor of "<<node1<<" and "<<node2<<" is: "<<s1.top();
            break;
        }
        else
        {
            s1.pop();
            s2.pop();
        }
    }

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
    LowestCommonAncestor(root,8,12);
}
