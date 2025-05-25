// minAbsoluteDiffInBST.cpp

/*

Given the root of a Binary Search Tree (BST), 
return the minimum absolute difference between the values of any two different nodes in the tree.


Example 1:

Input: root = [4,2,6,1,3]
Output: 1


Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 10pow4].
0 <= Node.val <= 10pow5
 
Note: This question is the same as 783: 
https://leetcode.com/problems/minimum-distance-between-bst-nodes/

*/

#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
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

    int diff = INT_MAX;
    TreeNode *prev = NULL;

    void dfs(TreeNode *root) {
        // moving to the left as much as we can
        if (root->left) dfs(root->left);
        
        // if we find at least a node before, we update diff
        if (prev) diff = min(diff, abs(prev->val - root->val));

        prev = root;
        // moving to the right as much as we can
        if (root->right) dfs(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return diff;
    }

};