// leetcode 144
/*

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

*/