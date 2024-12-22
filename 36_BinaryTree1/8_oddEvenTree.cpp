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
 

/*
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false

*/

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* currNode = root;

        queue <TreeNode*> q;
        q.push(currNode);
        
        bool isEven = true; // initially level is even -> then flip the isEven bool check... after each level.....

        while(!q.empty()){
            int sz = q.size();

            int prev = INT_MAX;
            if (isEven) prev = INT_MIN;    // even level mai increasing chahiya isliye...

            while(sz--){    // yahi accha tarika hota hai while loop waala...
                currNode = q.front();
                q.pop();

                if (isEven && (currNode->val %2 == 0 || currNode->val <= prev)) return false;
                if (!isEven && (currNode->val %2 != 0 || currNode->val >= prev)) return false;

                prev = currNode->val;       // to move on to move on to move on...

                // pushing their relatives in bfs...
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);

            }
            isEven = !isEven;  
        }
        return true;   
    }
};