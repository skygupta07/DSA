#include <iostream>
using namespace std;
int main(){

}  


// lc 100
/*

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL && q==NULL) return true;
        if (p==NULL && q!=NULL) return false;
        if (p!=NULL && q==NULL) return false;
        
        if (p->val!= q->val) return false;
        bool lstAns = isSameTree(p->left, q->left);
        bool rstAns = isSameTree(p->right, q->right);
        if (lstAns == false) return false;
        if (rstAns == false) return false;
        // if none of the above case hits means both the trees are same..
        return true;
        
    }
};

*/


/*  method-2

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p==NULL || q==NULL)  return (p==q);

        return ( (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right) );  
    }
};


*/