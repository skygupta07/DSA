// sumOfLeftLeaves.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node

*/


//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// bfs approach....
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;            // !root matlab if (root == NULL) return 0;

        queue <pair <TreeNode*, bool>> q;        // (node, is_left)
        q.push({root , false}); // initiating the reaction by pushing root and its identity...
        int totalSum = 0;

        while (!q.empty()){
            // front pop push

            auto [node , isLeft] = q.front();  
            q.pop();
             // good method to fetch pair values...ha ab mai yahi use karta hu..issey ye bhi dhyan rehta h ki mene datastructure
            //  mai kya kya paramters initialise kiye they..

            if (isLeft && !node->left && !node->right) totalSum += node->val;

            if (node->left) q.push({node->left , true});
            if (node->right) q.push({node->right , false});       // if(node->right) ka matlab hai if (node->right != NULL)
        }

        return totalSum;
    }
};



// -------dfs approach---------

class Solution {
public:
    int dfs(TreeNode* node, bool isLeft){
        if (!node) return 0;

        // if it is a leaf node and also left leaf node then add its contribution....
        if (!node->left && !node->right) return isLeft ? node->val : 0;
        
        int leftSum = dfs(node->left,true);
        int rightSum = dfs(node->right, false);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
};