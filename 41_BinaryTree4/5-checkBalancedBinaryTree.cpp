/*

class Solution {
public:
    int dfsHeight(TreeNode* &root){
        if (root == NULL) return 0;

        int lh = dfsHeight(root->left);
        if (lh == -1) return -1;

        int rh = dfsHeight(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;
        return 1 + max(lh,rh);      // for height calculation
    }


    bool isBalanced(TreeNode* root){
        return dfsHeight(root) != -1;   // ekdum end moment mai game khela...
    }
};

*/