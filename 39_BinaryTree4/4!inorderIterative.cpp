#include <iostream>
#include <vector>
using namespace std;

vector <int> inorderIterative(TreeNode* root){
    vector <int> ans;
    if (root == NULL) return ans;

    stack <TreeNode*> st;
    // threshold 
    st.push(root);

    while (!st.empty()){
        TreeNode* tp = st.top();   
        st.pop();

        if (tp->right){
            st.push(tp->right);
        }

        ans.push_back(tp->val);

        if (tp->left){
            st.push(tp->left);
        }
    }

    return ans;

}



/*
actually we are not doing anything new just we are using actual stack to avoid recursion 
auxiliary stack space...

just upar neeche karna hai code ko..


*/