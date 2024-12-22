#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Helper function to construct the BST recursively
    TreeNode* helper(vector<int> &arr, int lo, int hi) {
        // Base case: if the subarray is empty, return NULL (leaf node)
        if (lo > hi) return NULL;
        
        // Find the middle element to make it the root of the current subtree
        int mid = lo + (hi - lo) / 2;
        
        // Create a new TreeNode with the middle element
        TreeNode* root = new TreeNode(arr[mid]);
        
        // Recursively construct the left subtree from the left half of the array
        root->left = helper(arr, lo, mid - 1);
        
        // Recursively construct the right subtree from the right half of the array
        root->right = helper(arr, mid + 1, hi); // was asked in OA of singh
        
        // Return the root node of this subtree
        return root;
    }
    
    // Main function to convert the sorted array to a height-balanced BST
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        // Call the helper function to start the recursion from the entire array
        return helper(arr, 0, arr.size() - 1); 
    }
};
