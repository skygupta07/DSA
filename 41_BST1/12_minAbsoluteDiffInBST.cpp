#include <bits/stdc++.h>
using namespace std;


/*
Given a binary search tree having n (n>1) nodes, the task is to find the
minimum absolute difference between any two nodes.
*/

class Solution{
public:
    
    void helper(Node* root, vector <int> &inorderArr){
        if (root == NULL) return;
        // left root right
        
        helper(root->left , inorderArr);
        inorderArr.push_back(root->data);
        helper(root->right , inorderArr);
    }
    
    int absDiff(vector <int> &inorderArr){
        // two pointers i, j
        int i = 0 , j = 1;
        int minVal = INT_MAX;
        
        while (j <= inorderArr.size() - 1){
            minVal = min( minVal , abs( inorderArr[i] - inorderArr[j] ) );
            i++;
            j++;
        }
        return minVal;
    }
    
    
    
    int absolute_diff(Node *root){
        // inorder traversal put in array then find the min. consecutive element difference...
        vector <int> inorderArr;
        
        helper(root, inorderArr);
        return absDiff(inorderArr);
    }
};
