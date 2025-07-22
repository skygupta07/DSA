// subtreeOfAnotherTree.cpp

/*

Given the roots of two binary trees root and subRoot, 
return true if there is a subtree of root with the same structure and node values of subRoot 
and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree 
and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

Example 1:

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true


Example 2:

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-1e4 <= root.val <= 1e4
-1e4 <= subRoot.val <= 1e4

*/



#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q){

        // agar dono mai se koi bhi null hua to jabardasti dono ko hi null hona padega..
        if (!p || !q){
            return (p == NULL && q == NULL);
        }

        // agar values same h to chalo ab left aur right mai bhi check karo...
        else if (p -> val == q-> val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }

        // agar values bhi same nahi aa rahi to kahe ka sameTree !!
        else return false;

    }


    bool isSubtree(TreeNode* p, TreeNode* q) {  // to check if q is subroot of p or not
        // if the father is NULL then search karna bekar h..
        if (!p) return false;

        // agar root se hi subroot mil jae to good h ...nahi to root ke left aur right mai chal ke explore karenge...
        else if (isSameTree(p, q)) return true;
        
        else{
            return (isSubtree(p->left, q) || isSubtree(p->right, q));
        }
    }
};


/*

first find the subroot in root (if not found then return false)
then isSameTree lagao..
(but i guess method would be good for bst)

*/