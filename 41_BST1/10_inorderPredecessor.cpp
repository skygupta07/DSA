#include<iostream>
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

TreeNode* inorder(TreeNode* root){   //inorder traversal: left root right
    if (root == NULL) return NULL;  // base case

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
    return root;
}

TreeNode* insertIntoBST(TreeNode* root, int data){
    TreeNode* temp = new TreeNode(data);
    if (root == NULL) return temp;  // for the very first node to be inserted

    else if (data < root->data){  // go left...
        if (root->left == NULL) root->left = temp;  // inserting that element
        else insertIntoBST(root->left, data);  // recursive call
    }

    else{  // go right...
        if (root->right == NULL) root->right = temp;
        else insertIntoBST(root->right, data);
    }

    return root;
}



TreeNode* inorderPred(TreeNode* root){  // for inorder predecessor...
    if (root == NULL) return NULL;

    TreeNode* pred = root->left;   // predecessor nikalne ke liye ek baar sach mai LEFT 
                                    // then right right chalte raho...
    while (pred->right != NULL){
        pred = pred->right;
    }

    return pred;  // finally pred is the required node...
} 


int main(){
    TreeNode* a = new TreeNode(1);
    insertIntoBST(a , 2);
    insertIntoBST(a , 3);
    insertIntoBST(a , 4);
   
    
    insertIntoBST (a , 9);
    insertIntoBST(a , 5);
    insertIntoBST(a , 6);
    

    insertIntoBST(a,8);
    inorder(a);   
    cout<<endl; 
    



}

/*

You are given root node of the BST and the key node of the tree. You need to find the in-order successor
and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and 
the number just greater than the target is the successor

*/




struct Node{

	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution{
    public:
    
    void findPred(Node* root, Node* &pre, int key){
        while (root != 0){
            if (key <= root->key) root = root->left;
            else{
                pre = root;
                root = root->right;
            }
        }
    }
    
    void findSucc(Node* root, Node* &succ, int key){
        
        while(root != 0){
            if (key >= root->key) root = root->right;
            else{
                succ = root;
                root = root->left;
            }
        }
    }
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        findPred(root, pre, key);
        findSucc(root, suc, key);
    }

    
};