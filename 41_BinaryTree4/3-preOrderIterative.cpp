/*

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector <int> preOrder;
        // if empty tree case then return the empty vector as it is...
        if (root == NULL) return preOrder;

        stack <TreeNode*> st;
        st.push(root);  // initial step
        while (!st.empty()){
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            
            // since stack is lifo so push right first
            if (root->right != NULL){
                st.push(root->right);
            }
            if (root->left != NULL){
                st.push(root->left);
            }
        }
        return preOrder;
        
    }
};


*/