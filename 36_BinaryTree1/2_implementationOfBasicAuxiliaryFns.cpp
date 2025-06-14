#include<bits/stdc++.h>
using namespace std;

class TreeNode{  // okay so leetcode uses ListTreeTreeNode or TreeTreeTreeNode and all to distinguish kaha ka TreeTreeNode
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){ // constructor is initialised in the TreeTreeNode class itself...
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(TreeNode* root){ // preOrder Traversal
    if (root==NULL) return;  // ye cheez dhyan rakhna ki abhi bhi aapka root wahi sabse upar wala nahi hai 
                            // uski help se to hum cheezo ko sort kar rahe hai.. basically root is a TreeTreeTreeNode Pointer
                            // to wo ab ghumte ghumte jab neeche jaake null ho jae tab phir wapas return jaana hoga
    cout<<root->data<<" ";  // beech mai apna kaam karlo...
    display(root->left);
    display(root->right);
}

int sum(TreeNode* root){
    if (root==NULL) return 0; // mana ki leaf TreeNode ki value aapki zero hai(tej ho rahe ho..)
    return root->data + sum(root->left) + sum(root->right);
            // root + left recursion + right recursion
}

int NodesNumber(TreeNode* root){    // size of tree is number of TreeNode
    if (root==NULL) return 0; // wapas jaaana hai magar int ans bhi dena hai to zero ko yaad kiya.
                // saap bhi mar jaye aur laathi bhi naa tute...
    return 1 + NodesNumber(root->left) + NodesNumber(root->right); // recursion magic..
}

int maxInTree(TreeNode* root){
    if (root == NULL) return INT_MIN;  // agar search karte karte root leaf TreeNode tak aagye 
    // tab to proper acchi comparison karne ke liye between root left or right aap int min hi return karo... 
    
    int lMax = maxInTree(root->left);
    int rMax = maxInTree(root->right);

    return max(root->data,max(lMax,rMax));  // max(a,max(b,c)) -> OA mistake done
}

int minInTree(TreeNode* root){
    if (root == NULL) return INT_MAX;

    int lMin = minInTree(root->left);
    int rMin = minInTree(root->right);

    return min(root->data, min(lMin, rMin));  // min(a,min(b,c)) - or simply tuple form mai bhi likh sakte ho... {a, b, c, d..}
}

int levelOfTree(TreeNode* root){    // or max depth of tree also..
    // no. of levels = 1 root ke karan plus left aur right me jiski jai uske number of levels...
    if (root == NULL) return 0;

    return 1 + max(levelOfTree(root->left), levelOfTree(root->right));
}   // 1 plus karne waali trick....



int main(){
    TreeNode* a = new TreeNode(1);  // first TreeNode is the root TreeNode..
    TreeNode* b = new TreeNode(2);  // since humne upar TreeNode ki definition hi aisi likhi hai ki
                            // now har new TreeNode ke pass left aur right child TreeNode honge..
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    
    // connecting TreeNodes
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

 /*   //    1
     //    /\ 
    //    2 3
    //   /\ /\ 
    //   4 5 6 7

*/
    // maximum questions of tree can be solved by recursion...
    display(a);
    cout<<endl;

    cout<<"sum of all elements of tree is: "<<sum(a);
    cout<<endl;

    cout<<"Number of TreeNodes in tree is: "<<TreeNodesNumber(a);
    cout<<endl;

    cout<<"max element in tree is: " <<maxInTree(a);
    cout<<endl;

    cout<<"min element in tree is: "<<minInTree(a);
    cout<<endl;

    cout<<"level of tree is: "<<levelOfTree(a);
    cout<<endl;

    int height = levelOfTree(a)-1;
    cout<<"height of tree is: "<<height<<endl;

}