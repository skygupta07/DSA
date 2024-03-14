// 1038. Binary Search Tree to Greater Sum Tree

// Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key
//  of the original BST is changed to the original key plus the sum of all 
//  keys greater than the original key in BST.
/*

class Solution {
public:
    int sum = 0;
    void inorderRev(TreeNode* &root){
        if (root == NULL) return;
        // right root left
        inorderRev(root->right);
        root->val += sum;
        sum = root->val;
        inorderRev(root->left); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorderRev(root);
        return root;  
    }
};




// reverse inorder is a good method to traverse the bst in reverse order or in desc order
*/