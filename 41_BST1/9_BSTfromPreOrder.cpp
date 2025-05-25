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
 
class Solution {
public:

    void insertIntoBST(TreeNode* &root, int val){
        if (root == NULL) return;
        TreeNode* temp = new TreeNode(val);

        if (val < root->val){
            // kya saste mai kaam ho jaega..nalle berojgar chapri ....
            if (root->left == NULL) root->left = temp;
            insertIntoBST(root->left, val);
        }

        if (val > root->val){
            // kya re bhikmangiya ... kya dekh rha h .. halwa h kya ...
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


/*

1008. Construct Binary Search Tree from Preorder Traversal
preOrder array mai simply traverse karo and insert into bst call kar do...

*/

/*


To reconstruct the unique structure of an arbitrary binary tree (not bst), we would need 
inorder traversal along with one of the others (preorder or postorder). - asked in mock interview

For Binary Search Trees (BSTs), either the preorder or postorder traversal is sufficient 
to uniquely determine the structure of the tree. This is because the BST property 
(left subtree < root < right subtree) constrains the possible arrangement of nodes, 
allowing for unique reconstruction.


*/

