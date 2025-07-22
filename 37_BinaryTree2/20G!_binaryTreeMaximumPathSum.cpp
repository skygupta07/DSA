// binaryTreeMaximumPathSum.cpp

/*

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes 
in the sequence has an edge connecting them. A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:

Input: root = [1,2,3]
Output: 6

Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.


Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42

Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 1e4].
-1000 <= Node.val <= 1000

*/

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

 #include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

// Definition of the TreeNode is assumed to be provided like:
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x): val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:

    // Global variable to keep track of the **maximum path sum** found so far.
    // This is updated during recursion whenever we find a new candidate path.
    int maxSum; 
        
    // Recursive helper function to compute the maximum path sum from the current node downward
    int solve(TreeNode* root) {
        
        // Base Case: If the node is NULL (empty ** subtree **), contribute 0 to the path sum
        if (root == NULL) return 0;
    
        // Recursively compute the maximum path sum **from left and right subtrees**

        // Only include them if they are **positive** 
        // (because negative values would decrease our path sum)

        int leftSum = max(0, solve(root->left));    // Don't include negative left paths
        int rightSum = max(0, solve(root->right));  // Don't include negative right paths
    
        // Compute the **path sum passing through this node** (includes root + left + right)
        // This represents the case where this node is the "peak" or "turning point" of the path
        int currSum = root->val + leftSum + rightSum;
    
        // Update the **global maxSum** if the current path is better than what we’ve found so far
        maxSum = max(maxSum, currSum);
    
        // Now decide which single path (left or right) should be passed **upwards** to the parent
        // We can **only choose one** direction to continue the path (left or right), not both
        // So we return the value of the current node + the larger of the two child path sums
        return root->val + max(leftSum, rightSum);
    }
    
    // Main function to be called externally
    int maxPathSum(TreeNode* root) {
        // Initialize the maxSum to the **smallest possible value** to ensure it gets updated
        // This is important in case all node values are negative (we still want the largest)
        maxSum = INT_MIN;

        // Start the recursive processing from the root
        solve(root);

        // After the entire tree is processed, return the best path sum found
        return maxSum;
    }

};
