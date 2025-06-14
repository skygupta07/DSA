// mirrorTree.cpp

/*

Given a binary tree, convert the binary tree to its Mirror tree.

Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children 
of all non-leaf nodes interchanged.     

Examples:

Input: root[] = [1, 2, 3, N, N, 4]
Output: [1, 3, 2, N, 4]

Explanation: 

In the inverted tree, every non-leaf node has its left and right child interchanged.
Input: root[] = [1, 2, 3, 4, 5]
Output: [1, 3, 2, N, N, 5, 4]

Explanation:

In the inverted tree, every non-leaf node has its left and right child interchanged.

Constraints:

1 ≤ number of nodes ≤ 1e5
1 ≤ node->data ≤ 1e5

*/


#include <bits/stdc++.h>
using namespace std;


class Node{
public:

    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


class Solution {
    public:
      // Function to convert a binary tree into its mirror tree.
      
      void dfs(Node* node){
          if (node == NULL) return;
          
          swap(node->left, node->right);
          
          dfs(node->left);
          dfs(node->right);
      }
      
      void mirror(Node* node) {
          dfs(node);
      }
  };