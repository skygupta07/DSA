#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, return an array of the largest value in each row 
of the tree (0-indexed).
 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]


Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-2pow31 <= Node.val <= 2pow31 - 1

*/


class TreeNode{
public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }

};


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
       
        vector <int> ans;

        if (root == NULL) return ans;

        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int qSize = q.size();

            int maxi = INT_MIN;

            while(qSize--){
                TreeNode* curr = q.front();
                q.pop();

                maxi = max(maxi, curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(maxi);
        }

        return ans;
    }
};