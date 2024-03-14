// lc 98 -> inorder of bst should be sorted to be a valid bst..

/*
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &v){
        if (root == NULL) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }

    bool isSorted(vector <int> &v){
        for(int i =1; i<v.size(); i++){
            if (v[i] <= v[i-1] ) return false;
        }
        return true;
    }

    bool isValidBST(TreeNode* root){
        vector<int> v;
        inorder(root,v);
        bool ans = isSorted(v);
        return ans; 
    }
};


// check if (root->val > max(LST) && root->val < min(RST)) then it is valid 
// or if inorder or bst is sorted then only it is valid bst






*/