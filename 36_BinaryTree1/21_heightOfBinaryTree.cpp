// heightOfBinaryTree.cpp


#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* root) {
         if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
       
        return 1 + max(height(root->left), height(root->right));
    }
};