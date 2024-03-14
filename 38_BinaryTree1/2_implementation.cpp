#include<iostream>
using namespace std;

class node{  // okay so leetcode uses ListNode or TreeNode and all to distinguish kaha ka node
public:
    int data;
    node* left;
    node* right;

    node(int data){ // constructor is initialised in the node class itself...
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void display(node* root){ // preOrder Traversal
    if (root==NULL) return;  // ye cheez dhyan rakhna ki abhi bhi aapka root wahi sabse upar wala nahi hai 
                            // uski help se to hum cheezo ko sort kar rahe hai.. basically root is a TreeNode Pointer
                            // to wo ab ghumte ghumte jab neeche jaake null ho jae tab phir wapas return jaana hoga
    cout<<root->data<<" ";  // beech mai apna kaam karlo...
    display(root->left);
    display(root->right);
}

int sum(node* root){
    if (root==NULL) return 0; // mana ki leaf node ki value aapki zero hai(tej ho rahe ho..)
    return root->data + sum(root->left) + sum(root->right);
            // root + left recursion + right recursion
}

int nodesNumber(node* root){    // size of tree is number of node
    if (root==NULL) return 0; // mana ki leaf node ki value aapki zero hai
    return 1 + nodesNumber(root->left) + nodesNumber(root->right); // recursion magic..
}

int maxInTree(node* root){
    if (root==NULL) return INT_MIN;  // agar search karte karte root leaf node tak aagye 
    // tab to proper acchi comparison karne ke liye between root left or right aap int min hi return karo... 
    int lMax = maxInTree(root->left);
    int rMax = maxInTree(root->right);
    return max(root->data,max(lMax,rMax));  // max(a,max(b,c))
}

int minInTree(node* root){
    if (root==NULL) return INT_MAX;
    int lMin = minInTree(root->left);
    int rMin = minInTree(root->right);
    return min(root->data,min(lMin,rMin));  // min(a,min(b,c))
}

int levelOfTree(node* root){    // or max depth of tree also..
    // no. of levels = 1 root ke karan plus left aur right me jiski jai uske number of levels...
    if (root==NULL) return 0;
    return 1 + max(levelOfTree(root->left),levelOfTree(root->right));
}   // 1 plus karne waali trick....



int main(){
    node* a = new node(1);  // first node is the root node..
    node* b = new node(2);  // since humne upar node ki definition hi aisi likhi hai ki
                            // now har new node ke pass left aur right child node honge..
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);
    
    // connecting nodes
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

    cout<<"Number of nodes in tree is: "<<nodesNumber(a);
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