#include <iostream>
using namespace std;
int main(){

}

/*
// lc 236
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

// p aur q kis part of tree mai lie kar rahe hai uspe depend karega ki 
// ancestor kya hoga...



