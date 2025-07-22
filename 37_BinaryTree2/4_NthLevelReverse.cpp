#include <bits/stdc++.h>
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



void printNthLevelRev(TreeNode* root, int currLevel, int reqLevel){
    if (root == NULL) return;

    if (currLevel == reqLevel){
        cout<<root->data<<" ";
        return;
    }

    printNthLevelRev(root->right, currLevel+1, reqLevel); // just right ki call pehle kar di..
    printNthLevelRev(root->left, currLevel+1, reqLevel);  
}

// yaha bas recursive call ko up down karne se changes aate hai ....pre in post ke change se
// koi fark nahi pad rha...



int main(){
    TreeNode* a = new TreeNode(1); // tu ek node ke andar kucch bhi value daal but usko
    TreeNode* b = new TreeNode(2); // kisi naam se to pukarega hi...
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


 /*   //    1       -level 1
     //    /\ 
    //    2  3       --level 2
    //   /\ /\ 
    //   4 5 6 7    ---level 3

*/
 
    printNthLevelRev(a,1,3);  // currLevel = 1, reqLevel = 3 
    // void printLevel(TreeNode* root, int currLevel, int reqLevel){
    cout<<endl;
}
