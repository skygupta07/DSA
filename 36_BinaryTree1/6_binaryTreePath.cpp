#include <bits/stdc++.h>
using namespace std;

/*

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.


Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]


Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

*/


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// lc 257

class Solution {
public:
    void helper(TreeNode* root, string s, vector<string> &ans){
        if (root == NULL) return;   // kucch nahi karna wapas chalo back to upper nodes...
                                                // jaha se aaye they...

        string a = to_string(root->val);

        if (root->left == NULL && root->right == NULL){ // leaf node condition
            s += a; // iss last wale node ko bhi daal and then ab ek string ban gaya h...
                    //  issey ans vector mai daalna hoga...
            ans.push_back(s);   // next node pe aate hai to pichle root ki value fill karte hai...
            
            return;
        }
        
        helper(root->left, s+a+"->", ans);
        helper(root->right, s+a+"->",ans);
    }

    vector<string> binaryTreePaths(TreeNode* root){
        vector <string> ans;

        helper(root,"",ans);    //empty string to store case answer...
        
        return ans;  
    }
};



// dekho jo inbuilt fn hote wo lowercase mai hi hote hai and usually separated 
// by _  (underscore) .... (agar ye baat JS wale ne sun li to wahi goli maar dega...)