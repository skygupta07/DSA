// flipEquivalentBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;

/*

For a binary tree T, we can define a flip operation as follows: 
choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if 
we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, 
return true if the two trees are flip equivalent or false otherwise.


Example 1:

Flipped Trees Diagram
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.


Example 2:

Input: root1 = [], root2 = []
Output: true


Example 3:

Input: root1 = [], root2 = [1]
Output: false
 

Constraints:

The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].

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

    // Recursive DFS function to check flip equivalence
    bool dfs(TreeNode* &root1, TreeNode* &root2){

        // Case 1: Both nodes are NULL (leaf level) -> Equal
        if (!root1 && !root2) return true;

        // Case 2: One is NULL, the other is not -> Not equal
        if (!root1 || !root2) return false;

        // 👉 Case 3: Values at current nodes don't match
        if (root1->val != root2->val) return false;

        //  Try both possibilities:
        // Flip case: compare left subtree of root1 with right of root2, and vice versa

        bool flip = dfs(root1->left, root2->right) && dfs(root1->right, root2->left);

        // No flip case: compare left with left and right with right directly
        bool notFlip = dfs(root1->left, root2->left) && dfs(root1->right, root2->right);

        // If either works, trees are flip equivalent at this level
        return (flip || notFlip);
    }

    // Main function that kicks off the recursion
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};


/*

agar dono hi null to true.
ek null dusra not null to false...
aur agar dono ki value same nahi to bhi false...

now subtree ke liye karne ke liye dfs call lagaya... 
ya to flip karke ans aa jaye .. ya not flip karke...

*/