
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         TreeNode* temp = new TreeNode(val);
//         if (root == NULL) return temp;
        
//         else if (root->val > val){ // go left
//             if (root->left == NULL) root->left = temp;
//              // NULL pe jaake insert karne waala method 

//             else insertIntoBST(root->left, val);
//         }
        
    
//         else { 
//             if (root->right == NULL) root->right = temp;
            
//              // attach the temp node directly
//             else insertIntoBST(root->right, val);
//         }

//         return root;
//     }