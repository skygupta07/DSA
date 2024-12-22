#include <iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }

};

int levels(TreeNode* root){
    if (root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void printNthLevel(TreeNode* root, int currLevel, int reqLevel){
    if (root == NULL) return;  //base case
    if (currLevel == reqLevel){
        cout<<root->val<<" ";   // kaam
        return;   // agar required level pe aagaye ho then neeche jaane ki no need...
    }
    printNthLevel(root->left,currLevel+1,reqLevel);
    printNthLevel(root->right,currLevel+1, reqLevel);

}

void levelOrder(TreeNode* root){
    int n = levels(root);
    for (int i=1; i<=n; i++){
        printNthLevel(root,1,i);
    }

}


int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    // connecting nodes
    a->left = b;
    a->right =c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    levelOrder(a); // always we pass root of tree
    

}

/*

building foundation for dfs...
*/