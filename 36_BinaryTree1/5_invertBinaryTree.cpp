#include <iostream>
using namespace std;

// LBB
//lc 226

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
    void helper(TreeNode* root){
        if (root == NULL) return;

        TreeNode* temp = root->left;    // yes temp can store NULL node also...
        root->left = root->right;
        root->right = temp;

        helper(root->left); // recursively har node ke liye ye karna hai ye....
        helper(root->right);
    
        // dhyan rakhna ki mere ko bas root ki cheeze hi swap nahi karni thi...
        // mere ko pure tree pe lagana hai => apply recursion..   
    }

    TreeNode* invertTree(TreeNode* root){   
        helper(root);
        return root;
    }
};




// ha trees wale topic mai helper fn ki jarurat hoti hai...
// go recursively to each node and swap node->left and node->right
// and if you fall to a null node then no need to go further, simply return kar do..