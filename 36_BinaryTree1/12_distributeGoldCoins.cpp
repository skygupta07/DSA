#include <bits/stdc++.h>
using namespace std;

/*
You are given the root of a binary tree with n nodes where each node in the tree has
 node.val coins. There are n coins in total throughout the whole tree.
In one move, we may choose two adjacent nodes and move one coin from one node to 
another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin
*/

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
    int steps = 0;
    int dfs(TreeNode* node){
        if (node == NULL) return 0;

        int leftRequired = dfs(node->left);
        int rightRequired = dfs(node->right);   

        steps += abs(leftRequired) + abs(rightRequired);
        
        return (node->val - 1) + leftRequired + rightRequired;
    }



    int distributeCoins(TreeNode* root) {
        dfs(root);
        return steps;
    }

};


/*
amount mere ko recursive call mai waapas aate waqt calculate karni hai.....so written post recursive call.....
time and space complexity of simple dfs i.e. O(n)

*/