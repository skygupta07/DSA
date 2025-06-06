/*

You are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure. 

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.


Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
 

Follow up: A solution using O(n) space is pretty straight-forward. 
Could you devise a constant O(1) space solution?


*/


#include <bits/stdc++.h>
using namespace std;


struct TreeNode{
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:

    // Inorder traversal to store nodes in sorted order
    void inorder(TreeNode* root, vector<TreeNode*>& v) {
        if (root == NULL) return;

        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    void recoverTree(TreeNode* root) {
        vector <TreeNode*> v; // bahut dino baad vector mene int ke alawa kisi aur ka dekha...
        inorder(root, v); 

        TreeNode* first = NULL;
        TreeNode* second = NULL;

        // Find the two misplaced nodes
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i]->val > v[i + 1]->val) {
                if (!first) {
                    first = v[i];  // First misplaced node
                }
                second = v[i + 1];  // Second misplaced node (updated if another inversion exists)
            }
        }

        // Swap the values of the misplaced nodes to correct the BST
        if (first && second) swap(first->val, second->val);
    }
};
