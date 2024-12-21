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
}


class Solution{    // for bst 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;  // issey nahi likha to phir kya likha..
        
        if (root->val == p->val || root->val == q->val) return root;    // descendant wala case
        else if (p->val < root->val && q->val > root->val) return root;
        else if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

// p chota q bada obviously root se hi comparison hoga... ya p bada q chota to root return karo..
// p bhi chota q bhi chota left mai recursive check karo..



// simply binary tree ka bhi accept kar leta hai leetcode..

/*
class Solution {
public:
     bool exists(TreeNode* root, TreeNode* target){
        if (root == NULL) return false;
        if (root == target ) return true;
        return exists(root->left,target) || exists(root->right,target);

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;
        else if (exists(root->left, p) && exists(root->right,q)) return root;
        else if (exists(root->right,p) && exists(root->left, q)) return root;
        else if (exists(root->left,p) && exists(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if (exists(root->right, p) && exists(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};

*/


int main(){

}