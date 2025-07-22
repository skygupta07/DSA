// largestBST.cpp


#include <bits/stdc++.h>
using namespace std;


/*

You're given a binary tree. 
Your task is to find the size of the largest subtree within this binary tree 
that also satisfies the properties of a Binary Search Tree (BST). 
The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, 
the left child is less than the node, and the right child is greater than the node, 
without any duplicate values in the subtree.


Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3

Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy


Input: root = [6, 7, 3, N, 2, 2, 4]
Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 1e5
1 ≤ node->data ≤ 1e5

*/

// Tree node structure used in the program


struct Node {
    int data;
    Node *left;
    Node *right;


    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
        // Helper function which returns vector of 4 elements:
        // [0] => IsBST (1 if true, 0 if false)
        // [1] => Size of BST
        // [2] => Minimum value in subtree
        // [3] => Maximum value in subtree

        vector <int> solve(Node* root) {
            // Base Case: NULL node => valid BST of size 0
            if (root == NULL) return {1, 0, INT_MAX, INT_MIN};
    
            // Leaf Node is always a BST
            if (root->left == NULL && root->right == NULL) return {1, 1, root->data, root->data};
    
            // Recursive call on left and right subtrees
            vector <int> left = solve(root->left);
            vector <int> right = solve(root->right);
    
            // Check if both left and right subtrees are BSTs
            if (left[0] && right[0]) {
                // Now check if current node satisfies BST properties:
                // root->data should be > max in left subtree AND < min in right subtree
                if (root->data > left[3] && root->data < right[2]) {
    
                    // Calculate min and max of the current subtree
                    int subtreeMin = min(root->data, left[2]);
                    int subtreeMax = max(root->data, right[3]);
    
                    // Size of BST rooted at current node
                    int subtreeSize = left[1] + right[1] + 1;
    
                    return {1, subtreeSize, subtreeMin, subtreeMax};
                }
            }
    
            // If current subtree is not BST, return max size of valid BST in left or right
            return {0, max(left[1], right[1]), 0, 0};  // min and max values don't matter here
        
        }

    
        // Main function to return the size of largest BST subtree
        int largestBst(Node* root) {

            vector <int> result = solve(root);

            return result[1]; // [1] => size of largest BST

        }

    };
    