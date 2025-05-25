// kthSmallestElementInBST.cpp


/*

Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1


Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) 
and you need to find the kth smallest frequently, how would you optimize?

*/


#include <bits/stdc++.h>
using namespace std;

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

class Solution {
public:

    void inorder(TreeNode* root, vector <int> &v){
        if (root == NULL) return;

        // left kaam right
        inorder(root -> left, v);
        v.push_back(root->val);
        inorder(root -> right, v);
    }


    int kthSmallest(TreeNode* root, int k) {
        vector <int> sortedArray;

        inorder(root, sortedArray);

        return sortedArray[k-1];
    }

};


class Solution {
public:

    void inorder(TreeNode* root, int k, int &count, int &ans){  // count and answer need to be passed by reference...
        if (root == NULL) return;

        // left root right
        inorder(root->left, k, count, ans);

        count++;

        if (count == k){
            ans = root -> val;
            return;
        }

        inorder(root->right, k, count, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        
        inorder(root, k, count , ans);

        return ans;
    }
};




// jab dimag mai bhusa bhara ho tab ye approach code karna...

class Solution { 
public:
    void preOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;
        
        //root, left, right 
        v.push_back(root->val);

        preOrderTraversal(root->left, v);
        preOrderTraversal(root->right, v);      
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        preOrderTraversal(root, v);

        sort(v.begin(), v.end());

        return v[k-1];
    }
};