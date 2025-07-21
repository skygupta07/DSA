// companies mai binary tree invert karne ko nahi bolenge...
// but your iq and logic should be well enough to learn and perform other
// taks as well....

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, invert the tree, and return its root.


Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]


Example 2:


Input: root = [2,1,3]
Output: [2,3,1]


Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

// LBB
// lc 226

struct TreeNode
{
    int val;

    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(TreeNode *root) {
        if (root == NULL)
            return;

        TreeNode *temp = root->left; // yes temp can store NULL node also...
        root->left = root->right;
        root->right = temp;

        solve(root->left); // recursively har node ke liye ye karna hai ye....
        solve(root->right);

        // dhyan rakhna ki mere ko bas root ki cheeze hi swap nahi karni thi...
        // mere ko pure tree pe lagana hai => apply recursion..
    }

    TreeNode *invertTree(TreeNode *root){
        solve(root);
        return root;
    }
};

// ha trees wale topic mai solve fn ki jarurat hoti hai...
// go recursively to each node and swap node->left and node->right
// and if you fall to a null node then no need to go further, simply return kar do..
