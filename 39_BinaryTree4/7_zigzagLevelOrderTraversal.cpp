// binaryTreeZigZagLevelOrderTraversal.cpp

/*

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between). 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector <vector <int>> zigzagLevelOrder(TreeNode* root){
        vector <vector <int>> result;
        if (root == NULL) return result;
        
        bool flag = 1;  // means left to right traversal
        queue <TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            int qSize = q.size();
            vector <int> row(qSize);  // row, level, temp, v kucch bhi bolo bas wo lal wala button click ho 
                                    // jana chahiye...
            // front po push   

            for (int i=0; i<qSize; i++){
                TreeNode* node = q.front();
                q.pop();

                // find position to fill the node's value
                // ye pattern bhi kai jagah dekh liya like ... ya to i pe work karo ya phir n-1-i  par...
                int idx = (flag) ? i : (qSize-1 - i);
                row[idx] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            // toggle flag after every level
            flag = !flag;

            result.push_back(row);
        }
        return result;  
    }
};


/*
using queue we do normal level Order Traversal 
now we will maintain a bool flag which will help us to fill the result in zig zag pattern 
complement the flag after each level....
*/

