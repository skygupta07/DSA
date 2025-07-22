#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};



void levelOrder(TreeNode* root){
    queue <TreeNode*> q;
    // created a queue with name q which will contain TreeNode* as items
    // pura node hi daalna hai node ki value nahi daalni...
    q.push(root);   // sabse pehle node push karwao.. ha node push to karni hi padegi....
    
    while(q.size() > 0){
        TreeNode* temp = q.front(); // or curr
        q.pop();

        cout<<temp->data<<" ";

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }

    cout<<endl;
}


int main(){
    TreeNode* a = new TreeNode(1); // tu ek node ke andar kucch bhi value daal but usko
    TreeNode* b = new TreeNode(2); // kisi naam se to pukarega hi...
    TreeNode* c = new TreeNode(3);

    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    
    TreeNode* g = new TreeNode(7);
    
    // connecting nodes

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    levelOrder(a);
}

// okay now i understood why to po push is used in c++
// because by default inbuilt queue pop ka return type void hota hai...tabhi pehle top
// then pop then push....

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ans;

        if (root == NULL) return ans; // ye to likhna hi padta h

        queue <TreeNode*> q;    
        q.push(root);

        while(!q.empty()){
            int qSize = q.size();
            vector <int> v;
        
            while (qSize--){
                TreeNode* curr = q.front();
                q.pop();

                v.push_back(curr->data);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            ans.push_back(v);
        }
        
        return ans;
    }
};


// bfs