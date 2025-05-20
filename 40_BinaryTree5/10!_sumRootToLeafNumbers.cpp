// sumRootToLeafNumbers.cpp


/*

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

Example 1:

Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.


Example 2:

Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

*/


#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
        // data members 
      int val;
      TreeNode *left;
      TreeNode *right;

      // constructor
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. 

Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children
*/

class Solution {
public:

    int sumNodes(TreeNode* &root, int currSum){
        if (root == NULL) return 0; // nalla case   

        // in general if you reach a node then
        currSum = currSum*10 + root->val;   // kai log iss kaam ko two steps mai bhi karte h (including me 🥲)

        // base case or terminating condition or jo bola tha waha tak pahuch gaye...
        if (root->left == NULL && root->right == NULL){
            // I am at leaf node...
            return currSum;
        }
        
        int leftSum = sumNodes(root->left, currSum);
        int rightSum = sumNodes(root->right, currSum);

        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root){
        // I remember I wasted around 1 hour time figuring out how to do this question, coz I was not 
        // passing currSum from this function 
        int currSum = 0;
        return sumNodes(root, currSum);   
    }

};