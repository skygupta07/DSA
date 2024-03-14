/*

class Solution {
public:
    void insertIntoBST(TreeNode* &root, int val){
        if (root == NULL) return;
        TreeNode* temp = new TreeNode(val);

        if (val < root->val){
            if (root->left == NULL) root->left = temp;
            insertIntoBST(root->left, val);
        }

        if (val > root->val){
            if (root->right == NULL) root->right = temp;
            insertIntoBST(root->right, val);
        }
    }


    TreeNode* bstFromPreorder(vector<int>& arr) {
        int n = arr.size();
        TreeNode* root = new TreeNode(arr[0]); // root
        // insert other elements
        for (int i=1; i<n; i++){
            insertIntoBST(root,arr[i]);
        }
        return root;   
    }
};

*/



/*
1008. Construct Binary Search Tree from Preorder Traversal
preOrder array mai simply traverse karo and insert into bst call kar do...
*/
