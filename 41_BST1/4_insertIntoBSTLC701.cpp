#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor 
    TreeNode(int data){  
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = new TreeNode(val);
        if (root == NULL) return temp;
        
        else if (root->val > val){ // go left
            if (root->left == NULL) root->left = temp;
             // NULL pe jaake insert karne waala method 

            else insertIntoBST(root->left, val);
        }
        
    
        else { // go right
            if (root->right == NULL) root->right = temp;
            
             // attach the temp node directly
            else insertIntoBST(root->right, val);
        }

        return root;
    }
};

int main(){

}