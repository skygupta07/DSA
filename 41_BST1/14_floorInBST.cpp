#include <bits/stdc++.h> 
using namespace std;
// code360
/*

Problem statement
You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.
Note :‘X’ is not smaller than the smallest node of BST .

For example:
In the above example, For the given BST  and X = 7, the greatest value node of the BST  which is smaller than or equal to  7 is 6.
Detailed explanation ( Input/output format, Notes, Images )

Constraints:
1 <= T <= 5
1 <= N <= 5 * 10 ^ 3
1 <= nodeVal[i] <= 10 ^ 9

Time Limit: 1 sec.


Sample Input 1:
2
10 5 15 2 6 -1 -1 -1 -1 -1 -1
7
2 1 3 -1 -1 -1 -1
2
Sample Output 1:
6
2
Explanation of Sample Input 1:
In the first test case, the BST looks like as below:
The greatest value node of the BST which is smaller than or equal to  7 is 6.

In the second test case, the BST looks like as below:
The greatest value node of the BST which is smaller than or equal to  2 is 2.


Sample Input 2:
2
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
15
5 3 10 2 4 6 15 -1 -1 -1 -1 -1 -1 -1 -1
8
Sample Output 2:
15
6

*/

template <typename T>
class TreeNode {
public:

        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
};


int floorInBST(TreeNode <int> *root, int x){
    // kyuki smaller value find karni hai to isliye nallo pe max return karna padega..
    if (root == NULL) return INT_MAX;   
    
    if (root -> val == x) return root -> val; // agar same hi number mil jae to balle balle..
    if (root -> val > x) return floorInBST(root->left, x);  // target urf x small h to left mai search karo...

    int potential = floorInBST(root->right, x);

    return potential <= x ? potential : root->val;
}


/*

start at the root node.
if root -> val > key  (key is smaller ) then the floor of the key must 
lie in the left subtree.
else floor may lie in the right subtree but only if there is a value lesser than 
or equal to the key. If not, then the root is the key.

*/