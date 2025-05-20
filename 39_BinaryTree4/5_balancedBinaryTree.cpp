// balancedBinaryTree.cpp

/*

Given a binary tree, determine if it is height-balanced.

 A height-balanced binary tree is a binary tree in which the depth 
 of the two subtrees of every node never differs by more than one.

*/


#include <bits/stdc++.h>
using namespace std;


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
    // This function returns the height of the tree if it is balanced,
    // otherwise, it returns -1 indicating that the tree is not balanced.
    int dfsHeight(TreeNode* &root){
        // Base case: If the node is NULL, return height as 0.
        if (root == NULL) return 0;

        // Recursively calculate the height of the left subtree.
        int lh = dfsHeight(root->left);
        // If the left subtree is unbalanced, return -1 immediately.
        if (lh == -1) return -1;

        // Recursively calculate the height of the right subtree.
        int rh = dfsHeight(root->right);
        // If the right subtree is unbalanced, return -1 immediately.
        if (rh == -1) return -1;

        // If the height difference between the left and right subtree is more than 1, 
        // return -1 indicating the current subtree is not balanced.
        if (abs(lh - rh) > 1) return -1;

        // If the subtree is balanced, return the height of the subtree (1 + max(lh, rh)).
        return 1 + max(lh, rh);  // height is one plus the maximum height of left and right subtree
    }

    // This function calls dfsHeight and checks if the tree is balanced.
    bool isBalanced(TreeNode* root){
        // If dfsHeight returns -1, the tree is not balanced, otherwise, it is balanced.
        return dfsHeight(root) != -1;   // returns true if balanced, false otherwise
    }
    
};
