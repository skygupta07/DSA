#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    bool dfs(TreeNode* &root1, TreeNode* &root2){
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        bool flip = dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        bool notFlip = dfs(root1->left, root2->left) && dfs(root1->right, root2->right);

        return flip || notFlip;
    }


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};


/*
agar dono hi null to true.
ek null dusra not null to false...
aur agar dono ki value same nahi to bhi false...

now subtree ke liye karne ke liye dfs call lagaya... 
ya to flip karke ans aa jaye .. ya not flip karke...
*/