#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node. 
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == NULL) return NULL; // Agar tree empty hai, toh bas NULL return karo.

        // Queue for BFS traversal
        queue <TreeNode*> q;
        q.push(root);

        vector<int> values; // To store values of nodes at the current level.
        int level = 0;      // Start with level 0 (even).

        // Perform BFS traversal
        while (!q.empty()) {
            int qSize = q.size();    // Number of nodes at the current level.
            
            // isme sabse badi chalaki yahi h ki saath mai ek vector leke chalo....
            vector<int> temp;        // Temporary vector for the current level values.

            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front(); // Current node
                q.pop();

                if (level % 2 == 1) { // Odd level: Replace the node's value with the reversed value.
                    node->val = values[qSize-1-i];
                }

                // Push the children of the current node into the queue for the next level.
                if (node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val); // Store the value for processing.
                }

                if (node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val); // Store the value for processing.
                }
            }

            // Update `values` to `temp` for the next odd level.
            values = temp;

            level++; // Move to the next level.
        }
        
        return root; // Return the modified tree.
    }
};
