// levelOrderTraversal_bfs.cpp

#include <bits/stdc++.h>
using namespace std;

//  A binary tree Node
class Node {
public:

    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;

        left = nullptr;
        right = nullptr;
    }

};


class Solution {
public:
  
    void bfs(Node* root, vector <vector <int>> &ans){
        if (root == NULL) return;
        
        queue <Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            vector <int> v;
            int qSize = q.size();
            
            for (int i=0; i<qSize; i++){
                Node* curr = q.front();
                q.pop();
                
                v.push_back(curr->data);
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            
            ans.push_back(v);
        }
        
    }
  
  
  
    vector <vector<int>> levelOrder(Node *root) {
         vector <vector <int>> ans;
         
         bfs(root, ans);
         
         return ans;
    }
};