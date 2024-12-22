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
        if (depth == 1){
            TreeNode* currNode = root;
            TreeNode* newNode = new TreeNode(val);

            newNode-> left = currNode;
            return newNode;
        }

        dfs(root, val , depth , 1);
                    // current depth = 1
        return root;
    }
};

// t.c. = O(n) -> since simply bas gaye hi to hai waha pura thodi chale gaye...
// s.c. = O(n) -> stack space...

