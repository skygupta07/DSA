#include <bits/stdc++.h>
using namespace std;

/*

Given two integer arrays, preorder and postorder where preorder is the preorder traversal 
of a binary tree of distinct values and postorder is the postorder traversal of the same tree, 
reconstruct and return the binary tree.

If there exist multiple answers, you can return any of them.


Example 1:

Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
Output: [1,2,3,4,5,6,7]


Example 2:

Input: preorder = [1], postorder = [1]
Output: [1]
 

Constraints:

1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.

postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.

It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal 
of the same binary tree.

*/

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
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            stack <TreeNode*> nodes; // Stack to maintain the construction of the tree
    
            // Create root node using the first element of preorder traversal
            TreeNode* root = new TreeNode(preorder[0]);
            nodes.push(root); // Push root node to stack
    
            int preIdx = 1, postIdx = 0; // Indices to track traversal in preorder and postorder
    
            while (!nodes.empty()) { // Loop until all nodes are processed
                TreeNode* curr = nodes.top(); // Get the current node from stack
    
                // If the current node matches the postorder node, pop it (it means both its children are processed)
                if (curr->val == postorder[postIdx]) {
                    nodes.pop();
                    postIdx++; // Move postorder index forward
                } 

                else{ // Otherwise, create a new node from preorder traversal
                    TreeNode* newNode = new TreeNode(preorder[preIdx++]); // Create a new node
    
                    // Attach the new node as left child if left child is not present
                    if (!curr->left) curr->left = newNode;
                    else curr->right = newNode; // Otherwise, attach as right child
    
                    nodes.push(newNode); // Push the new node to stack for further processing
                }
                
            }
    
            return root; // Return the constructed binary tree
        }
    };
    