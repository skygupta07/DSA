#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == NULL) return ans;   // nalla

        queue <TreeNode*> q;
        q.push(root);   // threshold

        // bfs or level order traversal
        while (!q.empty()){
            int qSize = q.size();   // mandatory

            for (int i=0; i<qSize; i++){ // yahi to catch hota hai bfs mai..
                 TreeNode* temp = q.front();
                 q.pop();

                // majak mat kar yrr
                 if (temp->left) q.push(temp->left);
                 if (temp->right) q.push(temp->right);

                // chalaki
                 if (i == qSize-1) ans.push_back(temp->val);
            }
        }

        return ans;
    }
};


/*
level order traversal karta hu... bas har level ka last wala element store karna hai....

*/