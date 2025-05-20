#include <bits/stdc++.h>
using namespace std;

class TreeNode{ 
public:
    // data members
    int val; // data or val 
    TreeNode *left, *right; // asked in interview..

    // constkructors with varying use...(constkructor overloading)
    TreeNode(){
        this->val = 0;
        left = NULL;
    }
    TreeNode(int val){
        this->val = val; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

// to remember

class Solution {
public:

    vector <int> inorderTraversal(TreeNode* root) {
        vector <int> ans;
        stack <TreeNode*> stk; // using stack since iteratively karna h...
        TreeNode* current = root;

        while (current != NULL || !stk.empty()) {
            // Traverse the left subtree
            while (current != NULL) {
                stk.push(current);  // Push the current node onto the stack
                current = current->left;  // Move to the left child
            }

            // Process the node on top of the stack
            current = stk.top();
            stk.pop();

            // Add the node's value to the result
            ans.push_back(current->val);  

            // Move to the right subtree
            current = current->right;
        }
        return ans;
    }
};