// sameTree.cpp

/*

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, 
and the nodes have the same value.


Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true


Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false


Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-1e4 <= Node.val <= 1e4

*/


#include <bits/stdc++.h>
using namespace std;


int main(){

}  

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// lc 100

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p==NULL && q==NULL) return true;
        
        if (p==NULL && q!=NULL) return false;
        if (p!=NULL && q==NULL) return false;
        
        if (p->val != q->val) return false;

        bool lstAns = isSameTree(p->left, q->left);
        bool rstAns = isSameTree(p->right, q->right);

        if (lstAns == false) return false;
        if (rstAns == false) return false;

        // if none of the above case hits means both the trees are same..
        return true;
        
    }
};




//   method-2

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p==NULL || q==NULL)  return (p==q);

        // matlab node left aur right teeno hi theek hone chahiye...
        return ( (p->val == q->val)
                 && isSameTree(p->left, q->left)
                && isSameTree(p->right, q->right) );  
    }
};


