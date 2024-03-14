#include <iostream>
using namespace std;
int main(){

}

/*
// lc 257

class Solution {
public:
    void helper(TreeNode* root, string s, vector<string> &ans){
        if (root == NULL) return;   // kucch nahi karna wapas chalo back to upper nodes...
                                                // jaha se aaye they...

        string a = to_string(root->val);
        if (root->left == NULL && root->right == NULL){ // leaf node condition
            s += a;
            ans.push_back(s);   // next node pe aate hai to pichle root ki value fill karte hai...
            return;
        }
        helper(root->left, s+a+"->", ans);
        helper(root->right, s+a+"->",ans);
    }

    vector<string> binaryTreePaths(TreeNode* root){
        vector<string> ans;
        helper(root,"",ans);    //empty string to store case answer...
        return ans;  
    }
};



*/


// dekho jo inbuilt fn hote wo lowercase mai hi hote hai and usually separated 
// by _  (underscore) ....