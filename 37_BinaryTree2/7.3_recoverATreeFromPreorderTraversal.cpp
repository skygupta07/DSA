// recoverATreeFromPreorderTraversal.cpp

#include <bits/stdc++.h>
using namespace std;

/*

We run a preorder depth-first search (DFS) on the root of a binary tree.
At each node in this traversal, we output D dashes (where D is the depth of this node), 
then we output the value of this node.  If the depth of a node is D, 
the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

Example 1:

Input: traversal = "1-2--3--4-5--6--7"
Output: [1, 2, 5, 3, 4, 6, 7]


Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]


Example 3:

Input: traversal = "1-401--349---90--88"
Output: [1, 401, null, 349, 88, 90]

*/



/**
 


 * Definition for a binary tree node.

 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 

 */



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
        TreeNode* recoverFromPreorder(string traversal) {
            int n = traversal.size();

            stack <pair <TreeNode*, int>> stk; // Stack to maintain (node, depth)
            int i = 0;
            
            while (i < n) {

                int depth = 0;

                // Count dashes to determine depth
                while (i < n && traversal[i] == '-') {
                    depth++;
                    i++;
                }
    
                // Extract the number (multi-digit handling)
                int num = 0;
                while (i < n && isdigit(traversal[i])) {
                    num = (num*10) + (traversal[i] - '0');

                    i++;
                }
    
                TreeNode* node = new TreeNode(num);
    
                // If stack is empty, it means this is the root node
                if (stk.empty()) {

                    stk.push({node, depth});
                    continue;

                }
    
                // Pop elements until we find the correct parent
                while (!stk.empty() && stk.top().second >= depth) stk.pop();
                
    
                // Attach this node to its correct parent
                if (!stk.empty()) {

                    TreeNode* parent = stk.top().first;

                    if (!parent->left) parent->left = node;
                    
                    else parent->right = node;
                    
                }
    
                // Push current node onto the stack
                stk.push({node, depth});
            }
    
            // Root of the tree is at the bottom of the stack
            while (stk.size() > 1) stk.pop();
            
            return stk.top().first;
        }
        
    };
    