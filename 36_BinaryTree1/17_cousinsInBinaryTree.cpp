// cousinsInBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree with unique values and the values of two different nodes 
of the tree x and y, return true if the nodes corresponding to the values x and y 
in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k 
node are at the depth k + 1.

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false


Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true


Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

*/




//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  
};
 

// method1
class Solution {
public:

    // BFS traversal to check if x and y are cousins
    void bfs(TreeNode* root, int x, int y, bool &ans){
        if (root == NULL) return; // base case

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int qSize = q.size();

            // flags to check if x and y found at current level
            bool xFound = false;
            bool yFound = false;

            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // agar current node ka left & right dono hai, toh check karo sibling condition
                if (curr->left && curr->right) {
                    int l = curr->left->val;
                    int r = curr->right->val;
                    
                    // agar x aur y siblings hain, toh wo cousins nahi ho sakte
                    if ((l == x && r == y) || (l == y && r == x)) {
                        ans = false;
                        return;
                    }
                }

                // check if current node itself is x or y
                if (curr->val == x) xFound = true;
                if (curr->val == y) yFound = true;

                // left and right child ko queue me daalo {again I forgot this }
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

            }

            // agar same level pe x & y dono mil gaye, aur siblings nahi the (checked above), 
            // then they surely are cousins
            if (xFound && yFound) {
                ans = true;
                return;
            }

            // agar same level pe sirf ek mila aur dusra nahi mila, 
            // toh wo same level pe nahi hain -> not cousins
            if ((xFound && !yFound) || (!xFound && yFound)) {
                ans = false;
                return;
            }

        }

        ans = false; // agar x aur y milte hi nahi hai tree me
    }

    // Main function
    bool isCousins(TreeNode* root, int x, int y) {
        bool ans = false;

        bfs(root, x, y, ans);

        return ans;
    }
};




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
            
            vector <TreeNode*> buf;  // Buffer to store the current level's nodes.
            
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
        
        // Return the modified root of the tree.
        return root; 
    }

};
