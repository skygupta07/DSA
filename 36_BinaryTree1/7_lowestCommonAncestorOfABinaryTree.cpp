// lowestCommonAncestor
#include <bits/stdc++.h>
using namespace std;

/*

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node 
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.


Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.


Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 1e5].
-1e9 <= Node.val <= 1e9
All Node.val are unique.
p != q
p and q will exist in the tree.

*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

// lc 236
class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target){

        if (root == NULL) return false;
        
        if (root == target ) return true;
        
        return exists(root->left, target) || exists(root->right, target);

    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;

        else if (exists(root->left, p) && exists(root->right, q)) return root;
        else if (exists(root->right, p) && exists(root->left, q)) return root;

        else if (exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if (exists(root->right, p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};



// p aur q kis part of tree mai lie kar rahe hai uspe depend karega ki 
// ancestor kya hoga...



