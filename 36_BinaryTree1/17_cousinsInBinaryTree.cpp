#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;  // The root has no cousins, so its value is set to 0.
        queue<TreeNode*> q;  // Queue for BFS traversal.
        q.push(root);  // Start with the root node.
        
        // Start BFS traversal level by level.
        while(!q.empty()){
            int n = q.size();  // Number of nodes at the current level.
            int sum = 0;  // To store the sum of all child nodes.
            vector<TreeNode*> buf;  // Buffer to store the current level's nodes.
            
            // Traverse all nodes at the current level.
            while(n--){
                TreeNode* node = q.front();  // Get the node at the front of the queue.
                q.pop();  // Remove it from the queue.
                buf.push_back(node);  // Store the node in the buffer for later updates.

                // Add the node's children to the queue for the next level.
                // Also, accumulate the values of the child nodes.
                if(node->left) {
                    q.push(node->left);  // Add left child to the queue.
                    sum += node->left->val;  // Add the left child's value to the sum.
                }
                if(node->right) {
                    q.push(node->right);  // Add right child to the queue.
                    sum += node->right->val;  // Add the right child's value to the sum.
                }
            }
            
            // Now, update the values of the child nodes based on the cousin sum logic.
            for(auto node: buf){
                // Start with the total sum of the next level's child nodes.
                int t = sum;
                
                // Subtract the value of the left child if it exists.
                if(node->left) t -= node->left->val;
                
                // Subtract the value of the right child if it exists.
                if(node->right) t -= node->right->val;
                
                // Set the value of the left child to the cousin sum (total sum - its sibling).
                if(node->left) node->left->val = t;
                
                // Set the value of the right child to the cousin sum (total sum - its sibling).
                if(node->right) node->right->val = t;
            }
        }
        
        return root;  // Return the modified root of the tree.
    }
};
