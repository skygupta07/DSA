#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != NULL || !st.empty()) {
            // Traverse the left subtree
            while (current != NULL) {
                st.push(current);  // Push the current node onto the stack
                current = current->left;  // Move to the left child
            }

            // Process the node on top of the stack
            current = st.top();
            st.pop();
            inOrder.push_back(current->val);  // Add the node's value to the result

            // Move to the right subtree
            current = current->right;
        }

        return inOrder;
    }
};