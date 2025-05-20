// maximumWidthOfBinaryTree.cpp

//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes
(the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes 
that would be present in a complete binary tree extending down to that level are also counted 
into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

class Solution {
public:

    int widthOfBinaryTree(TreeNode* root){
        // Base case: if the tree is empty, width is 0
        if (root == nullptr) return 0;

        long long maxi = 0; // To track the maximum width of the binary tree

        // Queue stores pairs of nodes and their relative* positions (long long to avoid overflow)
        queue <pair <TreeNode*, long long>> q;

        // Start with the root node at position 0
        q.push({root, 0});

        while (!q.empty()) {
            long long qSize = q.size(); // Number of nodes at the current level

            // Relative minimum position for this level to prevent overflow in large trees
            long long dmin = q.front().second;

            // To store the first and last positions at the current level
            long long first, last;

            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front().first; // Current node
                long long d = q.front().second - dmin; // Relative position of the current node
                q.pop();

                // Mark the first and last positions in the current level
                if (i == 0) first = d; 
                if (i == qSize - 1) last = d;

                // Add left child with updated position
                if (node->left) q.push({node->left, 2 * d + 1});

                // Add right child with updated position
                if (node->right) q.push({node->right, 2 * d + 2});
            }

            // Update maximum width using the positions at the current level, matlab wahi har level pe maximize karte raho width ko...
            // kya pta kaun sa level maxwidth de de...

            maxi = max(maxi, last - first + 1);
        }
        
        return maxi; // Return the maximum width found
    }
};

/*

Explanation:
1. The width of the binary tree is calculated at each level and is defined as: 
   width = last node's position - first node's position + 1 at a level.
    (literally I'm very much obsessed with this formula pattern like {right - left + 1} )
   
2. Each node is assigned a relative position based on its parent's position:
   - Left child: `2 * parent_position + 1`
   - Right child: `2 * parent_position + 2`

3. To handle large trees and avoid overflow in position calculations, we normalize the 
   positions at each level by subtracting `dmin` (the minimum position in the current level).

4. The algorithm uses a BFS approach (level-order traversal) with a queue to calculate 
   the width for each level and updates the maximum width.

Time Complexity:
- O(n), where n is the number of nodes in the binary tree (each node is visited once).

Space Complexity:
- O(w), where w is the maximum width of the binary tree (maximum number of nodes at any level).

*/
