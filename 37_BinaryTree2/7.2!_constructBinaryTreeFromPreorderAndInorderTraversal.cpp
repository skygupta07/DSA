// constructBinaryTreeFromPreorderAndInorderTraversal.cpp

/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal 
of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.


Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]


Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length

-3000 <= preorder[i], inorder[i] <= 3000

preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.

preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

*/



#include <bits/stdc++.h> // sabhi standard C++ libraries ek saath include ho jaate hain
using namespace std;

// TreeNode structure define kiya ja raha hai (Binary Tree ka ek node)
struct TreeNode {
    int val;               // node ka value
    TreeNode *left;        // left child ka pointer
    TreeNode *right;       // right child ka pointer

    // 3 types of constructors:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}                          // default constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}                    // sirf value wala constructor
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // value + children ke saath constructor
};


class Solution {
public:
    
    // Recursive function to construct tree using preorder and inorder arrays
    TreeNode* constructTree(vector <int> &preorder, int preStart, int preEnd, 
                            vector <int> &inorder, int inStart, int inEnd, 
                            map <int, int> &mp) {
        
        // Base case: agar invalid range hai to NULL return karo
        if (preStart > preEnd || inStart > inEnd) return NULL;

        // root node create karo preorder ke first element se
        TreeNode* root = new TreeNode(preorder[preStart]);

        // inorder me root element ki position find karo using map (mp)
        int elem = mp[root->val];

        // left subtree me kitne nodes hain uska count karo
        int nElem = elem - inStart;

        // left subtree banane ke liye recursive call:
        // preorder: agla element se lekar nElem elements tak
        // inorder: inStart se lekar elem - 1 tak
        root->left = constructTree(preorder, preStart + 1, preStart + nElem, 
                                   inorder, inStart, elem - 1, mp);

        // right subtree banane ke liye recursive call:
        // preorder: preStart + nElem + 1 se lekar preEnd tak
        // inorder: elem + 1 se lekar inEnd tak
        root->right = constructTree(preorder, preStart + nElem + 1, preEnd, 
                                    inorder, elem + 1, inEnd, mp);

        // root return karo jiske left & right set ho chuke hain
        return root;
    }

    // Main function to build tree from preorder and inorder
    TreeNode* buildTree(vector <int> &preorder, vector <int> &inorder) {
        int preStart = 0;
        int preEnd = preorder.size() - 1;

        int inStart = 0;
        int inEnd = inorder.size() - 1;

        // map to store element -> index of inorder
        map <int, int> mp;

        // inorder array ke har element ko uske index ke saath map me store karo
        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i; // e.g., inorder = [9,3,15,20,7] → mp[3] = 1, mp[15] = 2 ...
        }

        // recursive tree build function call karo
        return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }
};
