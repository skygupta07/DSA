// addOneRowToTree.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree and two integers val and depth, 
add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, 
create two tree nodes with value val as cur's left subtree root and right subtree root.

cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.

If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val 
as the new root of the whole original tree, and the original tree is the new root's left subtree.
 

Example 1:


Input: root = [4,2,6,3,1,5], val = 1, depth = 2
Output: [4,1,1,2,null,null,6,3,1,5]


Example 2:


Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]
 

Constraints:

The number of nodes in the tree is in the range [1, 1e4].
The depth of the tree is in the range [1, 1e4].
-100 <= Node.val <= 100
-1e5 <= val <= 1e5
1 <= depth <= the depth of tree + 1

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
    
    // standard name node se pass kiya ....
    void dfs(TreeNode* node, int val, int depth, int currDepth){
        if (node == NULL) return;

        if (currDepth < depth - 1){
            // in recursion call se desired Depth pe pahuch jaunga ek baar left mai ek baar right ke liye....
            // recursion apne aap hi handle karega .... at the end to root hi return karna hai...
            dfs(node->left, val, depth, currDepth + 1);
            dfs(node->right, val, depth, currDepth + 1);
        }

        if (currDepth == depth - 1){
            TreeNode* exLeftChild = node->left; // exLeftChild aur uske neeche ke bhi sab ussey judey honge ...
                    // value thodi le rahe hai hum to node le rahe hai....
            TreeNode* exRightChild = node->right;

            TreeNode* newLeftChild = new TreeNode(val);
            TreeNode* newRightChild = new TreeNode(val);

            node->left = newLeftChild;
            newLeftChild->left = exLeftChild;

            node->right = newRightChild;
            newRightChild->right = exRightChild;
        }
    }


    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // it is given in question in this case, aap left mai hi laga do..
        if (depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode-> left = root;
            return newNode;
        }

        dfs(root, val , depth , 1);
                    // current depth = 1

        return root;

    }
};

// t.c. = O(n) -> since simply bas gaye hi to hai waha pura thodi chale gaye...
// s.c. = O(n) -> stack space...

