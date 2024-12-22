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

// dry run done... it is amazing it works...
void printNthLevel(TreeNode* root, int currLevel, int reqLevel){
    if (root == NULL) return;  //base case yeh to sagun waala hai jo hamesha hi aana hi hai likhan hi padat
    if (currLevel == reqLevel){
        cout<<root->data<<" ";   // kaam
        return;   // agar required level pe aagaye ho then neeche jaane ki no need...
    }
    printNthLevel(root->left,currLevel+1,reqLevel);  // left call
    printNthLevel(root->right,currLevel+1,reqLevel); // right call
}


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
    //    2 3       --level 2
    //   /\ /\ 
    //   4 5 6 7    ---level 3

*/

    
    printNthLevel(a,1,3);  // currLevel = 1, reqLevel = 3 
    // void printLevel(TreeNode* root, int currLevel, int reqLevel){
    cout<<endl;
}





// BFS is implemented using queue (qatar football balondecruz)
                               //   (queue fifo bfs)
// DFS is implemented using stack (e.g. pre in postorder)
