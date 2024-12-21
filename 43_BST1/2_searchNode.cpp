#include <bits/stdc++.h>
using namespace std;

class TreeNode{ // I wrote this..
public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){     // constructor
                this->val = data;
                this->left = NULL;
                this->right = NULL;
        }    
};

// lc 700
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int target) {
        if (root==NULL) return NULL; // base case
        else if (root->val == target) return root;
        else if (root->val > target) return searchBST(root->left, target);   // target abhi chotta hai to left mai chalo..
        else return searchBST(root->right, target);    
    }
};


// else if isliye lagaya kyuki it is confirm ki left mai hoga to then right mai nahi hoga..




