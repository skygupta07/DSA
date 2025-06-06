#include <bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the leftmost value in the last row of the tree.

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
    int findBottomLeftValue(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            root = q.front();
            q.pop();

            if (root->right) q.push(root->right);
            if (root->left) q.push(root->left);
        }
          
        return root->val;
    }
};

// the very first element of the bottommost level will be answer...
// you just keep updating the root itself your final root will be your answer....

