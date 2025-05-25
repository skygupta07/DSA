// bstToGst.cpp

/*

Given the root of a Binary Search Tree (BST), 
convert it to a Greater Tree such that every key of the original BST is changed to the original key
plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]


Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
0 <= Node.val <= 100
All the values in the tree are unique.

*/


#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
public:

    int sum = 0;

    void inorderRev(TreeNode* &root){
        if (root == NULL) return;
        // right root left

        inorderRev(root->right);

        // root ki value ko update karte chalna h...
        root->val += sum;
        sum = root->val; // updating sum for next iteration...

        inorderRev(root->left); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorderRev(root);
        return root;  
    }
};

// 1038. Binary Search Tree to Greater Sum Tree

// reverse inorder is a good method to traverse the bst in reverse order or in desc order
