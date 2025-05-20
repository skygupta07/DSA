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


vector <int> inorderIterative(TreeNode* root){
    vector <int> ans;
    if (root == NULL) return ans;

    stack <TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()){
        TreeNode* curr = stk.top();   
        stk.pop();

// inorder - left root right -> magar yaha sach mai stack use kar rahe h to .. right root left karna hoga..

        if (curr->right) stk.push(curr->right);

        ans.push_back(curr->val);

        if (curr->left) stk.push(curr->left);
        
    }

    return ans;

}



/*
actually we are not doing anything new just we are using actual stack to avoid recursion 
auxiliary stack space...

just upar neeche karna hai code ko..


*/