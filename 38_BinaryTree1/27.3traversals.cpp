#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

void preOrder(node* root){
    if (root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if (root==NULL) return;    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if (root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int levelOfTree(node* root){ // counts number of levels in a tree..
    // no. of levels = 1 root ke karan plus left aur right me jiske jai uske number of levels...
    if (root==NULL) return 0;
    return 1 + max(levelOfTree(root->left),levelOfTree(root->right));
}

// 
void printNthLevel(node* &root, int currLevel, int targetLevel){  // fn resembling with preOrder..
    if (root==NULL) return;
    if(currLevel == targetLevel){
        cout<<root->data<<" ";
        return;  // optimised code..
    }    
    printNthLevel(root->left,currLevel+1,targetLevel);
    printNthLevel(root->right,currLevel+1,targetLevel);
}

void printNthLevelRev(node* root, int currLevel, int targetLevel){  // fn resembling with preOrder..
    if (root==NULL) return;
    if(currLevel == targetLevel){
        cout<<root->data<<" ";
        return;  // optimised code..4
    }
   
    printNthLevelRev(root->right,currLevel+1,targetLevel); 
    printNthLevelRev(root->left,currLevel+1,targetLevel);
}

void levelOrder(node* root){
    // print kar do aap nth level ko jitne aapke level hai utne times..
    int n = levelOfTree(root);
    for (int i=1; i<=n; i++){  // accha yaha ab i=1 ka use dikh rha hai...
        printNthLevel(root,1,i);
        cout<<endl;
    }

}

int main(){
    node* a = new node(1);  // first node is the root node..
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);
    node* f = new node(6);
    node* g = new node(7);

    /*//    1
     //    /\ 
    //    2 3
    //   /\ /\ 
    //   4 5 6 7

*/
  
    
    // connecting nodes
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    cout<<"preOrder Traversal is: ";
    preOrder(a);
    cout<<endl;

    cout<<"inorder Travesal is: ";
    inOrder(a);
    cout<<endl;

    cout<<"postorder Travesal is: ";
    postOrder(a);
    cout<<endl;

    printNthLevel(a,1,2);
    cout<<endl;

    levelOrder(a);
    cout<<endl;

    printNthLevelRev(a,1,3);


}


// these all are depth first search traversals i.e. 
// dfs traversals -> pre in postorder traversal

// pre in post order traversals taking t.c. = O(n) and s.c. = O(height) = O(logn) best case
// but in worst case s.c. = O(n) for skewed tree...
// becuause peak space ke case mai bhi maximum logn hi elements present they call stack mai..