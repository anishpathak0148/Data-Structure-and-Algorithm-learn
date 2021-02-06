#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node* CreateNode(int x)
{
    Node *temp = new Node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void InOrderTraverse(Node *root)
{
    if(root==NULL)
        return;
    InOrderTraverse(root->left);
    cout<<root->data<<"  ";
    InOrderTraverse(root->right);
}

void DiagonalTraverseUtil(Node *root, int d, map<int,vector<int>> &m)
{
    if(root==NULL)
        return;
    //Push all the nodes of same line together in vector
    m[d].push_back(root->data);
    //Increase the diagonal distance if child is left.
    DiagonalTraverseUtil(root->left, d+1, m);
    //Diagonal distance remains same for right child.
    DiagonalTraverseUtil(root->right, d, m);
}

void diagonalTraverse(Node *root)
{
    map<int,vector<int>>diagonalNode;
    int d=0;    //diagonal distance.
    DiagonalTraverseUtil(root, d , diagonalNode);

    for(auto i=diagonalNode.begin();i!=diagonalNode.end();i++)
    {
        vector<int>::iterator it=i->second.begin();
        while(it!=i->second.end())
        {
            cout<<*it<<" ";
            it++;
        }
        cout<<endl;
    }
}
main()
{

    Node *root = CreateNode(1);
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
    cout<<"In-order Traverse of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Diagonal Traverse of Tree is:"<<endl;
    diagonalTraverse(root);

    cout<<endl<<endl;
    root=NULL;

    root = CreateNode(8);
    root->left = CreateNode(3);
    root->right = CreateNode(10);
    root->left->left = CreateNode(1);
    root->left->right = CreateNode(6);
    root->right->right = CreateNode(14);
    root->right->right->left = CreateNode(13);
    root->left->right->left = CreateNode(4);
    root->left->right->right = CreateNode(7);
    cout<<"In-order Traverse of Tree is:"<<endl;
    InOrderTraverse(root);
    cout<<endl;
    cout<<"Diagonal Traverse of Tree is:"<<endl;
    diagonalTraverse(root);

}
