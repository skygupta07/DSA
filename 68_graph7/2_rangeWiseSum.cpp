/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    int inorder(TreeNode* root, int l, int r){
       if (root){
            inorder(root->left, l , r);

            if (root->val >= l && root->val <= r){
                sum += root->val;
            }

            inorder(root->right, l, r);
       }
       return sum;
    }


    int rangeSumBST(TreeNode* root, int l, int r) {
        if (!root) return 0;    // base case
        return inorder(root,l,r);
    }
};q