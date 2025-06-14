// diameterOfBinaryTree.cpp

/*
543. Diameter of Binary Tree

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 

This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

*/

#include <iostream>
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


    int levels(TreeNode* root){ // level of tree
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    void helper (TreeNode* root , int &maxdia){    // helper fn which further takes help of levels fn and calculate the
    // diameter of tree..
        if (root == NULL) return;   // base case 
        int currDia = levels(root->left) + levels(root->right); // kaam -> diameter nikala and then turant
        // maximise pe bhi laga diya...

        maxdia = max(currDia,maxdia);

        helper(root->left,maxdia); // recursively call lagai taaki saare nodes tak cover ho sake...
        helper(root->right,maxdia); 
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia = 0; // initialise...

        helper(root,maxdia); // helper or solve or f 

        return maxdia;
    }
};



/*
we can think that ans is standing on a root go to deep in left and go in deep of right 
then add both of them 
but it will be better that we calculate the path via ezch node ...
and update the maxdia via travelling only..(i.e. maximizing the global variable while doing your general
iteration work....)

*/




// -------- method - 2 -------------

class Solution {
public:
    int height(TreeNode* &node, int &diameter){ // if you want the same variable value to be reflected everywhere
                // then pass it by reference only....
        if (node == NULL) return 0;

        int lh = height(node->left,diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }

};


/*
we can think that ans is standing on a root go to deep in left and go in deep of right then add both o them 
but it will be better that we calculate the path via ezch node ...and update the maxdia via travelling only..

// i.e. we are trying to take the longest on every node considering that node as the curve point.....
*/


class Solution {
public:

    int maxDia = 0;


    int levels(TreeNode* root){
        if (root == NULL) return 0;

        return 1 + max(levels(root->left), levels(root->right));
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        int dia = levels(root->left) + levels(root->right);

        maxDia = max(maxDia,dia);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxDia;
    }
};



