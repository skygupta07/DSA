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
 


class Solution{
public:
    TreeNode* helper(TreeNode* &root, int target){
        if (root == NULL) return NULL;
        // delete karne mai problem aai to simply null hi attach kar diya..

        root->left = helper(root->left, target);
        root->right = helper(root->right, target);
        // pehle hi recursive call laga di... and wapas aate waqt mai leaf wali condition check kari and delete 
        // or null attach kiya....
        if (root->left == NULL && root->right == NULL && root->val == target) return NULL;

        return root;    
    }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = helper(root , target);
        return root;
    }
};


