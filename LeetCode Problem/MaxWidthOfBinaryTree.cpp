/*
Given a binary tree, write a function to get the maximum width of the given tree.
The width of a tree is the maximum width among all levels.
The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right..
most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input:

           1
         /   \
        3     2
       / \     \
      5   3     9

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input:

          1
         /
        3
       / \
      5   3

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input:

          1
         / \
        3   2
       /
      5

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

*/
#include<bits/bits/stdc++.h
using namespace std;

int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return -1;
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root, 1));
        int ans=0;
        while(!q.empty())
        {
            int ct = q.size();
            ans = max(ans, (q.back().second - q.front().second)+1);
            while(ct>0)
            {
                pair<TreeNode*,int> temp = q.front();
                q.pop();

                if(temp.first->left){
                    q.push(make_pair(temp.first->left, 2*(long)temp.second));
                }
                if(temp.first->right){
                    q.push(make_pair(temp.first->right, 2*(long)temp.second +1));
                }

                ct--;
            }
        }
        return ans;
}
