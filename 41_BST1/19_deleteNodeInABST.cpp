// deleteNodeInABST.cpp

/*


Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.


Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.


Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 
Follow up: Could you solve it with time complexity O(height of tree)?

*/


#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
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

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root){
            // Pehle hum tree me us node ko dhoondh rahe hain jo delete karni hai
            if (key < root -> val) root->left = deleteNode(root->left, key);  // Agar key choti hai toh left me dhoondo
            
            else if (key > root -> val) root->right = deleteNode(root->right, key); // Agar key badi hai toh right me dhoondo
            
            else {  
                // Yahan par hume wo node mil gayi jo delete karni hai

                // Case 1: Agar node ka koi bhi child nahi hai (Leaf Node)
                if (!root->left && !root->right) return NULL;

                // Case 2: Agar node ka sirf ek child hai
                if (!root->left || !root->right){
                    return (root->left) ? root->left : root->right; // Jo bhi child ho, usse upar bhej do
                }

                // Case 3(most important and interesting..): 
                // Agar node ke dono child hain, toh inorder predecessor se replace karo

                // predecessor ke liye ek pehle baar left then aakhiri saas tak right...
                TreeNode* temp = root->left;

                // Left subtree ka rightmost node (predecessor) find karna hai
                while (temp->right != NULL) temp = temp->right;

                // Predecessor ka value root me copy karo
                root->val = temp->val;

                // Predecessor ko delete kar do (issey kaise samjhu ?? ki delete bhi karna hota h !! sarcasm)
                root->left = deleteNode(root->left, temp->val); 
            }            
        }

        return root; // Final updated tree return kar rahe hain
    }
};
