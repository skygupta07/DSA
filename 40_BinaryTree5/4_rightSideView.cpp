// rightSideView.cpp

#include <bits/stdc++.h>
using namespace std;


class TreeNode{ 
public:
    // val members
    int val;    // data or val
    TreeNode *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    TreeNode(){
        this->val = 0;
        left = NULL;
    }
    TreeNode(int val){
        this->val = val; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};


class Solution {
public:
    vector <int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if (root == NULL) return ans;   // nalla

        queue <TreeNode*> q;
        q.push(root);   // threshold

        // bfs or level order traversal
        while (!q.empty()){
            int qSize = q.size();   // mandatory

            for (int i=0; i<qSize; i++){ // yahi to catch hota hai bfs mai..
                 TreeNode* curr = q.front();
                 q.pop();

                // majak mat kar yrr
                 if (curr->left) q.push(curr->left);
                 if (curr->right) q.push(curr->right);

                // chalaki
                 if (i == qSize-1) ans.push_back(curr->val);
            }
        }

        return ans;
    }
};


/*
level order traversal karta hu... bas har level ka last wala element store karna hai....

*/