#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]

*/


class Node{ 
public:
    // data members
    int data;
    Node *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    Node(){
        this->data = 0;
        left = NULL;
    }
    Node(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


#include <bits/stdc++.h>
using namespace std;

// ha result to reference se jaega... but path to variable hoga har path ke liye so ussey as such 
// reference se bhejne ki koi need nahi h...
void dfs(Node* root , vector<vector<int>> &result, vector <int> path){
    if (root == NULL) return;  // nalla
    
    path.push_back(root -> data);   // threshold -=> very first step or root node
    
    // leaf node tak aa gaye matlab ek path ban gya hoga...
    if (root -> left == NULL && root -> right == NULL){ 
        result.push_back(path);
    }
    
    else{   // recursive dfs calls
        if (root -> left ) dfs(root->left, result, path);
        if (root -> right) dfs(root -> right, result, path);
    }
    
    // backtrack - abey saale backtrack to last mai karega hi na...tabhi to dusre path pe jaega...
    path.pop_back();
}

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;    // nalla
        
        // ek chutki sindoor ki kimat tum kya jaano coder babu
        vector <int> path; 
        dfs(root, result, path);
        
        return result;
    }
};