// zigZagLevelOrderTraversal.cpp

/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

*/

#include <bits/stdc++.h>
using namespace std;


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

    int levelOfTree(TreeNode* &root){ // counts number of levels in a tree..
        // no. of levels = 1 root ke karan plus left aur right me jiske jai uske number of levels...
        if (root == NULL) return 0;

        return 1 + max(levelOfTree(root->left), levelOfTree(root->right));
    }

    void NthLevel(TreeNode* &root, int currLevel, int targetLevel, vector<int>&v){  // fn resembling with preOrder..
        if (root == NULL) return; // nalla ❌ NULL ✅

        // berojgar ❌ base case ✅
        if(currLevel == targetLevel){
            v.push_back(root->val);
            return;  // optimised code..
        }   

        // chappri ❌ call ✅
        NthLevel(root->left, currLevel+1, targetLevel, v);
        NthLevel(root->right, currLevel+1, targetLevel, v);

    }


    void NthLevelRev(TreeNode* &root, int currLevel, int targetLevel, vector<int>&v){  // fn resembling with preOrder..
        if (root == NULL) return;
        
        if(currLevel == targetLevel){
            v.push_back(root->val);
            return;  // optimised code..
        }    

        NthLevelRev(root->right, currLevel+1, targetLevel, v);
        NthLevelRev(root->left, currLevel+1, targetLevel, v);
    }

    void lOrder(TreeNode* &root, vector <vector <int>> &ans){
        // print kar do aap nth level ko jitne aapke level hai utne times..
        int n = levelOfTree(root);

        for (int i=1; i<=n; i++){  // accha yaha ab i=1 ka use dikh rha hai...
            vector <int> v;

            if (i%2 !=0){
                NthLevel(root, 1, i, v);
                ans.push_back(v);
            }

            else{
                NthLevelRev(root, 1, i, v);
                ans.push_back(v);
            }
        }

    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        lOrder(root, ans);
        
        return ans;
    }
    
};




