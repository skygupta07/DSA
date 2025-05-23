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
 
 // yeh cheej sahi kari ki bas leaf hi node mai value 0 aur 1 hai....
 // recursion apna kaam kardega bus aap jo soch rahe ho wo bas likh do...

class Solution {
public:
    bool helper(TreeNode* root){
        if (root->val == 0 || root->val == 1) return root->val;
        else if (root->val == 2) return helper(root->left) || helper(root->right);
        else if (root->val == 3) return helper(root->left) && helper(root->right);

        return 0;
    }

    bool evaluateTree(TreeNode* root) {
        return helper(root);
    }
};


