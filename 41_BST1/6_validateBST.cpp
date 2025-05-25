#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:

Input: root = [2,1,3]
Output: true


Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-2pow31 <= Node.val <= 2pow31 - 1

*/

class TreeNode{
public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};
// lc 98 -> inorder of bst should be sorted to be a valid bst..

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &v){
        if (root == NULL) return;
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    bool isSorted(vector <int> &v){
        for(int i =1; i<v.size(); i++){
            // same bhi nahi ho sakta aur bada bhi nahi ho sakta...
            if (v[i] <= v[i-1] ) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root){
        vector<int> v;
        inorder(root,v);

        bool ans = isSorted(v);
        return ans; 
    }
};


// check if (root->val > max(LST) && root->val < min(RST)) then it is valid 
// or if inorder or bst is sorted then only it is valid bst






