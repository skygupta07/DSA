// pathSum2.cpp

/*

Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node.
A leaf is a node with no children.


Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]

Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22


Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []


Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

*/



#include <bits/stdc++.h>
using namespace std;

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

    void findPath(TreeNode* &root, int targetSum, vector <vector <int>> &ans, vector <int> path){
        if (!root) return;

        // leaf node 
        if (!root->left && !root->right && root->val == targetSum){
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }

        // not leaf node
        // in general path mai add root->val and then left exist kar rha h to left, 
        // agar right exist kar rha h to right..
        path.push_back(root->val);

        // further call remaining sum se hoga...
        if (root->left) findPath(root->left, targetSum - root->val, ans, path);
        if (root->right) findPath(root->right, targetSum - root->val, ans, path);
    }


    vector <vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <vector <int>> ans;
        vector <int> path;

        findPath(root, targetSum, ans, path);
        
        return ans;
    }
};


class Solution {
public:

    void findPath(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> &path) {
        if (!root) return; // nalla

        path.push_back(root->val);  // include current node in path

        // If it's a leaf and sum matches, store the path {ye jo targetSum yaha h ye ekdum initial wala
        // nahi hoga.. ye ek tarah se maan lo remaining jo bacha hua sum h ye wo h...}

        // matlab sahi ki you landed at leaf node and uss leaf node ne bacha hua sum complete karwa diya... 
        // to chalo bhai ek path mil gaya...

        if (!root->left && !root->right && root->val == targetSum) {
            ans.push_back(path);
        } 
        
        else {
            // Recurse on left and right {with reduced sum} reduce sum to karna hi padega..
            findPath(root->left, targetSum - root->val, ans, path);
            findPath(root->right, targetSum - root->val, ans, path);
        }

        path.pop_back();  // Backtrack: remove current node before returning
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <vector <int>> ans;

        vector <int> path;

        findPath(root, targetSum, ans, path);

        return ans;
    }
};



/*

Time Complexity:

Worst case: O(N^2) where N = number of nodes
Each root-to-leaf path can take up to O(N), and there may be O(N) such paths in skewed trees.

Space Complexity:
Recursive stack: O(H), where H = height of tree
Answer list: O(K × N), where K = number of paths, N = max path length

*/