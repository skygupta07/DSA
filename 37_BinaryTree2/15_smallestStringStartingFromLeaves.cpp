// smallestStringStartingFromLeaves.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given the root of a binary tree where each node has a value in the range [0, 25] 
representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.


Example 1:

Input: root = [0,1,2,3,4,3,4]
Output: "dba"


Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"


Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25

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

    // Function to return the lexicographically smallest string from leaf to root
    string smallestFromLeaf(TreeNode* root) {
        string smallest; // Stores the final smallest string
        
        dfs(root, "", smallest); // Start DFS traversal from root
        
        return smallest; // Return the result
    }

    // Helper DFS function: traverses the tree and builds strings
    void dfs(TreeNode* node, string path, string &smallest) {
        // Base case: if current node is NULL, return
        if (node == nullptr) return;

        // Step 1: Convert current node's value (0-25) to corresponding char (a-z)
        // and append it to path. This builds the string from root to current node.
        path += char('a' + node->val);  // For example, node->val = 0 => 'a'

        // Step 2: Check if it's a leaf node (no left or right child)
        if (node->left == nullptr && node->right == nullptr) {
            
            // Since we want string from **leaf to root**, we reverse the path
            reverse(path.begin(), path.end());

            // Step 3: Compare with smallest string seen so far
            // If this is the first string or is lexicographically smaller, update `smallest`
            // yaha string comparison apne aap hi lexicographically hi ho rha hoga..
            if (smallest.empty() || path < smallest) {
                smallest = path;
            }

            // Backtrack step: reverse the path back to its original state 
            // (important if you’re reusing the same path variable)
            reverse(path.begin(), path.end());
        }

        // Step 4: DFS traversal on left and right subtrees
        dfs(node->left, path, smallest);
        dfs(node->right, path, smallest);
    }
};

/*

bhai graph traverse karne ke liye bfs/dfs traversal hi hota hai.... 
now it depends on you... how you write the code and modify it...

*/