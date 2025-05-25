#include <bits/stdc++.h>
using namespace std;

/*

Given a binary search tree (BST), find the lowest common ancestor (LCA) 
node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node 
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.


Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.

*/


class TreeNode{
public: 

    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};


 // for bst 
class Solution{   
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;  // issey nahi likha to phir kya likha..
        
        if (root->val == p->val || root->val == q->val) return root;    // descendant wala case
        
        // p left mai lie kar rha ho and q right mai to phir root hoga answer...
        else if (p->val < root->val && q->val > root->val) return root;

        // agar p aur q dono hi left mai lie kar rahe ho to left mai hi search kar lo...
        else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};

// p chota q bada obviously root se hi comparison hoga... ya p bada q chota to root return karo..
// p bhi chota q bhi chota left mai recursive check karo..





// simply binary tree ka bhi accept kar leta hai leetcode.. BST wale case mai bhi aaram se..
// finding LCA using the presence of different nodes in the tree...
class Solution {
public:
     bool exists(TreeNode* root, TreeNode* target){
        if (root == NULL) return false;
        
        if (root == target ) return true;
        return exists(root->left,target) || exists(root->right,target);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;

        else if (exists(root->left, p) && exists(root->right,q)) return root;
        else if (exists(root->right,p) && exists(root->left, q)) return root;

        else if (exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if (exists(root->right, p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};



