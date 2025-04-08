// sumRootToLeafNumbers.cpp

#include <bits/stdc++.h>
using namespace std;

/*
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children
*/

class Solution {
public:
    int sumNodes(TreeNode* &root ,int currSum){
        if (root == NULL) return 0;

        // in general if you reach a node then
        currSum = currSum*10 + root->val;
        if (root->left == NULL && root->right == NULL){
            // I am at leaf node...
            return currSum;
        }
        
        int leftSum = sumNodes(root->left, currSum);
        int rightSum = sumNodes(root->right, currSum);
        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root){
        int currSum = 0;
        return sumNodes(root,currSum);   
    }
};