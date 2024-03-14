#include<iostream>
#include<vector>
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

void preOrder(TreeNode* &root){ // t.c. = O(n) , s.c. = O(levels+1) = O(h+2) = O(height)
    if (root == NULL) return;   // return ka matlab hota hai call stack mai se ud gya..
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// in post mai bas ek line ka change....


int main(){
    TreeNode* a = new TreeNode(1); // tu ek node ke andar kucch bhi value daal but usko
    TreeNode* b = new TreeNode(2); // kisi naam se to pukarega hi...like a,b,c,d...
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

    preOrder(a);
    cout<<endl;
    
    

}

// T.C. = O(n) // where n is number of nodes, since visiting the node only once
// S.C. = O()  // due to call stack of recursion