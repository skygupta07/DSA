#include <bits/stdc++.h>
using namespace std;


// leetcode 144

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

    void preOrder(TreeNode* root, vector<int> &ans){        // mandatory to pass the vectors by reference
        if (root == NULL) return;
        ans.push_back(root->val);
        preOrder(root->left , ans);
        preOrder(root->right , ans);
    }



    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> ans;  // created a vector 
        preOrder(root,ans);   // done the work
           // return the answer
        return ans;
    }
    
};

