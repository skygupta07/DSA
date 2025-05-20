// univaluedBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;


/*
A binary tree is uni-valued if every node in the tree has the same value.

Given the root of a binary tree, return true if the given tree is uni-valued, 
or false otherwise.

Example 1:

Input: root = [1,1,1,1,1,null,1]
Output: true


Example 2:


Input: root = [2,2,2,5,2]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val < 100

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);

        int uniVal = root->val;

        while (!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if (curr->val != uniVal) return false;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        return true;
    }
};