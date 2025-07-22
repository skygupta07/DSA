/*

Given two integer arrays inorder and postorder where inorder is the inorder traversal 
of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.
 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd, unordered_map <int,int> &mp){
        if (inorderStart > inorderEnd || postorderStart > postorderEnd) return NULL; // base case...
        
        int rootVal = postorder[postorderEnd];
        // constructing tree start...
        TreeNode* root = new TreeNode(rootVal);
        int inorderRootIndex = mp[rootVal];
        int leftSubtreeSize = inorderRootIndex - inorderStart;
        root->left = buildTreeHelper(inorder,postorder , inorderStart, inorderRootIndex-1, postorderStart,postorderStart + leftSubtreeSize -1, mp);
        root->right = buildTreeHelper(inorder, postorder, inorderRootIndex + 1, inorderEnd, postorderStart + leftSubtreeSize, postorderEnd - 1, mp);
        return root;
    } 


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map <int,int> mp;
        for (int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i; // inorder traversal mai element ko uske index se map kiya...
        }
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }

};