#include <bits/stdc++.h>
using namespace std;

/*

You are given the root node of a binary search tree (BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, 
as long as the tree remains a BST after insertion. You can return any of them.


Example 1:

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]


Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.

*/


class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int data){ 
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


TreeNode* insertIntoBST(TreeNode* root, int data){
    TreeNode* temp = new TreeNode(data);    // sabse pehle pudiya to banao khaini rakhne ke liye...
                                        // sabse pehle node to banao TreeNode ki value ko store karne ke liye...
    
    // for the very first node to be inserted
    if (root == NULL) return temp;  

    // go left...
    else if (data < root->data){  
        if (root->left == NULL) root->left = temp;  // inserting that element
        else insertIntoBST(root->left, data);  // recursive call
    }

    // go right...
    else{ 
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

// recursion ke magic se obviously root pointer sach mai hi root pe aagya hoga

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