// pathSum3.cpp

#include <bits/stdc++.h>
using namespace std;

/*


Given the root of a binary tree and an integer targetSum, 
return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards 
(i.e., traveling only from parent nodes to child nodes).


Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.


Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-1e9 <= Node.val <= 1e9
-1000 <= targetSum <= 1000

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
    int count = 0;

    void dfs(TreeNode* root, long long sum){
        if (!root) return;

        if (root -> val == sum) count++;
        
        dfs(root -> left, sum - root->val);
        dfs(root -> right, sum - root -> val);
    }

    int pathSum(TreeNode* root, int sum) {
        
        if (root){
            dfs(root, sum);

            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }

        return count;
    }

};