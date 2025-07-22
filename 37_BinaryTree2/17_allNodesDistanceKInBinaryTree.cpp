// allNodesDistanceKInBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.


Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000

*/


struct TreeNode {

      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


// k distance par to koi node upar bhi ho sakta h ya phir neeche bhi paaya jaa sakta h...

class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Step 1: Create a map to store parent pointers of each node
        unordered_map<TreeNode*, TreeNode*> parentTrack; 

        // Map to track visited nodes to prevent cycles or re-visits
        unordered_map<TreeNode*, bool> visited; 

        // BFS queue for traversal
        queue<TreeNode*> q;
        q.push(root);

        // Step 1: Do BFS to build parent pointer map for each node
        while (!q.empty()) {
            TreeNode* curr = q.front(); // current node
            q.pop();

            // If left child exists, store its parent and add to queue
            if (curr->left) {
                parentTrack[curr->left] = curr; // child -> parent
                q.push(curr->left);
            }

            // If right child exists, store its parent and add to queue
            if (curr->right) {
                parentTrack[curr->right] = curr; // child -> parent
                q.push(curr->right);
            }
        }

        // Step 2: Start BFS from the target node
        // Queue is reused. Push target node as starting point.
        q.push(target);

        // Mark target node as visited
        visited[target] = true;

        int currLevel = 0; // Track current level of BFS (distance from target)

        // BFS until we reach distance K
        while (!q.empty()) {
            int qSize = q.size(); // nodes at current level

            // Agar k level tak pahuch gaye hain, break
            if (currLevel++ == k) break;

            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Visit left child if it exists and is unvisited
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // Visit right child if it exists and is unvisited
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // Visit parent node if it exists and is unvisited
                if (parentTrack.find(curr) != parentTrack.end() && !visited[parentTrack[curr]]) {
                    q.push(parentTrack[curr]);
                    visited[parentTrack[curr]] = true;
                }
            }
        }

        // Step 3: All nodes remaining in the queue are at distance K
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val); // store value of node
            q.pop();
        }

        return ans; // return all node values at distance k
    }
};

