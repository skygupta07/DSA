// houseRobber3.cpp

/*

The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, 
return the maximum amount of money the thief can rob without alerting the police.
 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.


Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 10pow4].
0 <= Node.val <= 10pow4

*/



//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

  };
 

// dp on tree
#include <bits/stdc++.h>
using namespace std;

struct RobbedRoot{
    int robbedRoot;  // Jab hum is node ko loot rahe hain
    int skippedRoot; // Jab hum is node ko skip kar rahe hain
};

class Solution {
public:
    RobbedRoot robDFS(TreeNode* root){
        
        if (root == NULL) return RobbedRoot{0, 0};  // Agar tree khatam ho gaya, toh dono 0 return karo

        RobbedRoot robLeft = robDFS(root->left);  // Left subtree ka result lao
        RobbedRoot robRight = robDFS(root->right); // Right subtree ka result lao

        // Current node lootne ka case
        int robThisNode = root->val + robLeft.skippedRoot + robRight.skippedRoot;

        // Current node skip karne ka case
        int skipThisNode = max(robLeft.robbedRoot, robLeft.skippedRoot) + max(robRight.robbedRoot, robRight.skippedRoot);

        return RobbedRoot{robThisNode, skipThisNode}; // Dono possibilities return karo
    }


    int rob(TreeNode* root) {
        RobbedRoot finalState = robDFS(root);
        
        return max(finalState.robbedRoot, finalState.skippedRoot); // Best possible chori ka sum return karo
    }
    
};


/*
 * Yeh approach DFS (Depth-First Search) + DP ka istemal karti hai taki har node se chori karne ya na karne ka best sum optimize ho sake.
 * Hum ek `RobbedRoot` struct banate hain jisme:
 *   - `robbedRoot`: Jab hum current node ko loot rahe hain, tab ka max sum.
 *   - `skippedRoot`: Jab hum current node ko nahi loot rahe, tab ka max sum.
 * 
 * DFS se tree traverse karte hain aur har node ke liye do cases consider karte hain:
 * 1. **Agar hum current node loot rahe hain**:
 *    - Toh hum uske directly connected left aur right child ko nahi loot sakte.
 *    - Toh `robbedRoot = root->val + left subtree ka skippedRoot + right subtree ka skippedRoot`
 * 
 * 2. **Agar hum current node nahi loot rahe**:
 *    - Toh hum left aur right dono se best possible chori ka sum le sakte hain.
 *    - `skippedRoot = max(left subtree ka robbedRoot, skippedRoot) + max(right subtree ka robbedRoot, skippedRoot)`
 * 
 * Har node ke liye ye dono cases calculate karke return kar dete hain.
 * 
 * Last me root ke dono possible values ka max return karenge taki best profit mile.
 */
