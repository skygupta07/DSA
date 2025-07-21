// 0.2_levelOrderTraversal2.cpp

/*

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
(i.e., from left to right, level by level from leaf to root). 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

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
 

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector <int>> ans;
        vector <int> level;

        // I'm a fool coz I forget its significance
        if (!root) return ans;

        // bfs
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int qSize = q.size();

            for (int i=0; i<qSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(level);

            level.clear(); // if you don't want to write this line so please declare the 
            // level vector inside the while loop
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};


class Solution {
public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector <int>> ans;
        
        if (!root) return ans;

        // bfs
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int qSize = q.size();
            vector <int> level;

            for (int i=0; i<qSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                level.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};