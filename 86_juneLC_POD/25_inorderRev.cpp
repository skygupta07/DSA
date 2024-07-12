#include <iostream>
#include <vector>
using namespace std;
int main(){

}



class Solution {
public:
    int sum = 0;

    void inorderRev(TreeNode* &root){
        if (root == NULL) return;
        // right root left
        inorderRev(root->right);
        root->val += sum;       // As we visit each node, we update its value by adding the     current sum to the node's value and then update sum to this new value.
        sum = root->val;
        inorderRev(root->left); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        inorderRev(root);
        return root;  
    }
};

/*
-- inorder of bst is sorted-----
--- reverse inorder will be reverse sorted.... pehle 8 then 7 then 6 ..

jab inorder traversal karte hai to left root right jisme sabse pehle min. element milta hai...
but jab reverse karenge to...yaha sabse pehle max. element milega..


Time Complexity: O(n), where n is the number of nodes in the BST. This is because we visit each node exactly once during the traversal.

Space Complexity: O(n) in the worst case due to the recursion stack. However, this can be reduced to O(h) where h is the height of the tree, if the tree is balanced.

*/