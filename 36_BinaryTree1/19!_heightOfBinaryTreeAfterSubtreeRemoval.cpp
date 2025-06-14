// heightOfBinaryTreeAfterSubtreeRemoval.cpp

#include <bits/stdc++.h>
using namespace std;

/*


You are given the root of a binary tree with n nodes. 
Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. 
It is guaranteed that queries[i] will not be equal to the value of the root.

Return an array answer of size m where answer[i] 
is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node 
in the tree.

Example 1:

Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]

Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).


Example 2:


Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]

Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. 
The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. 
The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. 
The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. 
The height of the tree becomes 2 (The path 5 -> 9 -> 3).
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 1e5

1 <= Node.val <= n

All the values in the tree are unique.

m == queries.length
1 <= m <= min(n, 1e4)

1 <= queries[i] <= n
queries[i] != root.val

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
 


class Solution {
public:
    // Arrays to hold:

    // depth[node] = height of subtree rooted at node
    // levelArr[node] = level (distance from root) of node

    // max1[level] = max depth at that level
    // max2[level] = second max depth at that level

    vector <int> depth, levelArr, max1, max2;

    // DFS function to compute depth and level for each node
    int height(TreeNode* root, int level) {
        
        if (!root) return 0;

        // Record the level of the current node
        levelArr[root->val] = level;

        // Recursively compute depth of left and right subtrees
        int left = height(root->left, level + 1);
        int right = height(root->right, level + 1);

        // depth of current node = 1 + max(left, right)
        depth[root->val] = 1 + max(left, right);

        // Update max1 and max2 for this level
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level];       // old max becomes second max
            max1[level] = depth[root->val];  // new max
        } 

        else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val];  // update second max only
        }

        return depth[root->val];  // return depth of current subtree
    }

    vector<int> treeQueries(TreeNode* root, vector <int> &queries){
        // Initialize arrays with sufficient size (constraints say up to 10^5)
        
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);

        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // First pass: compute depth and level for each node
        height(root, 0);

        // Process each query
        for (int i = 0; i < queries.size(); i++) {

            int q = queries[i];
            int level = levelArr[q];

            // If the node we are removing was the one contributing to the max height at this level,
            // use the second max height instead.
            int newMaxDepth = (max1[level] == depth[q] ? max2[level] : max1[level]);

            // Height of remaining tree = new max depth + level (from root) - 1
            queries[i] = newMaxDepth + level - 1;

        }

        return queries;
    }
};
