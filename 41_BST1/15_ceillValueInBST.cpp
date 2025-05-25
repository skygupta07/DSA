#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int x){
    if (root == NULL) return -1;
    
    int ceil = -1;

    while (root != NULL){

        if (root -> data == x){
            ceil = root->data;
            return ceil;
        }

        if (root->data < x) root = root-> right;

        else{
            ceil = root -> data;
            root = root-> left;
        }
    }

    return ceil;
}