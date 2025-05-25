#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
public:

    TreeNode *insertIntoBST(TreeNode *root, int val){

        TreeNode *temp = new TreeNode(val);
        
        if (root == NULL) return temp;

        // jo value insert karni h wo chotti h abhi current root se to phir ... pehle dekha kya iss root ka 
        // left khali h .. agar ha to yahi laga do nahi to go more left using recursive call...
        else if (root->val > val){ 

            if (root->left == NULL) root->left = temp;
            // NULL pe jaake insert karne waala method

            else insertIntoBST(root->left, val);
        }

        // go right
        else{ 
            if (root->right == NULL) root->right = temp;

            // attach the temp node directly
            else insertIntoBST(root->right, val);
        }

        return root;
    }
};
