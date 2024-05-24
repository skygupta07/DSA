#include<iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){ // constructor
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int data){
    TreeNode* temp = new TreeNode(data);    // sabse pehle pudiya to banao khaini rakhne ke liye...
                                        // sabse pehle node to banao TreeNode ki value ko store karne ke liye...
    if (root == NULL) return temp;  // for the very first node to be inserted

    else if (data < root->data){  // go left...
        if (root->left == NULL) root->left = temp;  // inserting that element
        else insertIntoBST(root->left, data);  // recursive call
    }

    else{  // go right...
        if (root->right == NULL) root->right = temp; //sabse pehle jaise hi khali
                                // jagah dikhti hai to wahi laga do else recursively find karo jagah
        else insertIntoBST(root->right, data);
    }
    return root;
}

TreeNode* inorder(TreeNode* &root){   // left root right -> inorder of Bst is sorted
    if (root == NULL) return NULL;  // base case

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return root;
}


int main(){
    TreeNode* ag = new TreeNode(1);
    insertIntoBST(ag,2);
    insertIntoBST(ag,3);
    insertIntoBST(ag,4);
    insertIntoBST(ag,5);
    insertIntoBST(ag,6);
    insertIntoBST(ag,7);
    
    inorder(ag);
    cout<<endl;
    TreeNode* inorderReturnValue = inorder(ag);
    cout<<inorderReturnValue->data<<endl;
    inorder(ag);
}