// binaryTreePath.cpp

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


// interviews
class Solution {
public:

    // Depth-First Search solve function to build root-to-leaf paths 
    // {dono path aur result dono ko hi reference se pass kiya....}

    void dfs(TreeNode* node, string &path, vector <string> &result) {
        // Base Case: If current node is NULL, return immediately (no further processing)
        if (!node) return;

        // Save the current length of the path string before modifying it.
        // This is essential for backtracking later (i.e., undoing changes after recursion).
        int originalLength = path.length();

        // Append the current node's value to the path string.
        // For example, if path is "1->2->" and node->val is 5, path becomes "1->2->5"
        path += to_string(node->val);

        // Check if this node is a **leaf node** (i.e., no left or right children).
        // If yes, then this path is complete, so add it to the result.
        if (!node->left && !node->right) {
            result.push_back(path);  // Store the complete root-to-leaf path
        } 
        
        
        else {
            // If not a leaf, we are still traversing, so add the path separator "->"
            path += "->";

            // Recursively call dfs on the left and right children to continue path building.
            dfs(node->left, path, result);
            dfs(node->right, path, result);

        }

        // After recursion, restore the path string back to its original length.
        // This step is **backtracking** – undo the changes made for the current node
        // so that sibling calls (or upper levels) don't get incorrect path content.
        path.resize(originalLength);
        
    }

    // Main function to be called from outside
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;   // This will store all the root-to-leaf path strings
        string path;             // Temporarily holds the path string during traversal
        
        dfs(root, path, result); // Start DFS traversal from the root
        
        return result;           // Return the final list of all paths
    }
};




 
// lc 257

class Solution {
public:

    void solve(TreeNode* root, string s, vector <string> &ans){
        if (root == NULL) return;   // kucch nahi karna wapas chalo back to upper nodes...
                                                // jaha se aaye they...

        string a = to_string(root->val);

        if (root->left == NULL && root->right == NULL){ // leaf node condition
            s += a; // iss last wale node ko bhi daal and then ab ek string ban gaya h...
                    //  issey ans vector mai daalna hoga...
            
            // next node pe aate hai to pichle root ki value fill karte hai...
            ans.push_back(s);  
            
            return;
        }
        
        solve(root->left, s+a+"->", ans);
        solve(root->right, s+a+"->",ans);

    }

    vector <string> binaryTreePaths(TreeNode* root){
        vector <string> ans;

        solve(root, "", ans);    //empty string to store case answer...
        
        return ans;  
    }
};



// dekho jo inbuilt fn hote wo lowercase mai hi hote hai and usually separated 
// by _  (underscore) .... (agar ye baat JS wale ne sun li to wahi goli maar dega...)

// __builtin_popcount(x) = gives the number of set bits in binary representation of x