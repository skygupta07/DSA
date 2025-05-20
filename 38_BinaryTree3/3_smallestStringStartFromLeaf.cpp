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

    string smallestFromLeaf(TreeNode* root) {
        string smallest;
        // ye empty path wagera bhejna na kisi vardaan se sach mai kam nahi hota...
        dfs(root, "", smallest);
        
        return smallest;
    }
    
    void dfs(TreeNode* node, string path, string &smallest) {
        if (node == nullptr) return;
        
        // Append current node's character to the path
        path += char('a' + node->val);
        
        // If it's a leaf node, compare and update smallest
        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());

            if (smallest.empty() || path < smallest) {
                smallest = path;
            }

            reverse(path.begin(), path.end()); // backtrack by reversing again
        }
        
        // Recursively traverse left and right subtrees
        dfs(node->left, path, smallest);
        dfs(node->right, path, smallest);

    }
};