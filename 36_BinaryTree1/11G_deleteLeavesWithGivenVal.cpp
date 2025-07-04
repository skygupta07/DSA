// deleteLeavesWithGivenValue.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, 
if its parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you cannot).


Example 1:

Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]

Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).


Example 2:


Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]


Example 3:

Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000

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

    TreeNode* solve(TreeNode* &root, int target){
        if (root == NULL) return NULL;
        // delete karne mai problem aai to simply null hi attach kar diya..

        root->left = solve(root->left, target);
        root->right = solve(root->right, target);

        // pehle hi recursive call laga di... and wapas aate waqt mai leaf wali condition check kari 
        // isliye taaki jo koi naya gunda bhi paida ho raha hoga ussey bhi 
        // marte huye chalenge... and delete 
        // or null attach kiya....kul mila ke usko pel ke bhaga diya...
        
        if (root->left == NULL && root->right == NULL && root->val == target) return NULL;

        return root;    
    }


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        root = solve(root , target);   // good way to handle scenario when solve void na ho ....
        return root;
    }
    
};