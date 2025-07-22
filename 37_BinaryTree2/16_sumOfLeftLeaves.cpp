// sumOfLeftLeaves.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.


Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000

*/



// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 


//  bfs queue (front pop push) level order
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;            // !root matlab if (root == NULL) return 0;

        queue <pair<TreeNode*, bool>> q;        // (node, is_left)
        q.push({root , false}); // initiating the reaction by pushing root and its identity...
        
        int totalSum = 0;

        while (!q.empty()){
            // fornt pop push
            auto [node , isLeft] = q.front();   // good method to fetch pair values...
            q.pop();

            if (isLeft && !node->left && !node->right) totalSum += node->val;

            if (node->left) q.push({node->left , true});

            // if(node->right) ka matlab hai if (node->right != NULL)
            if (node->right) q.push({node->right , false});       
        }

        return totalSum;
    }
};



//  dfs -> adding both leftSum and rightSum -> recursion handles itself
class Solution {
public:
    int dfs(TreeNode* node, bool isLeft){
        if (!node) return 0;

        // is ! not ko doube equal to NULL padha karo simply..
        
        // if it is a leaf node and also left leaf node then add its contribution....
        if (!node->left && !node->right) return isLeft ? node->val : 0;
        
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};



