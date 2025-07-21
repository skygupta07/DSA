// distributeGoldCoins.cpp

#include <bits/stdc++.h>
using namespace std;

/*


You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. 
There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. 
A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.

Example 1:


Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, 
and one coin to its right child.


Example 2:


Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. 
Then, we move one coin from the root of the tree to the right child.
 

Constraints:

The number of nodes in the tree is n.
1 <= n <= 100
0 <= Node.val <= n
The sum of all Node.val is n.

*/

struct TreeNode {
    int val; // Node ke paas kitne coins hain
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // we use this one
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:

    int steps = 0; // Total moves store karne ke liye

    // DFS function that returns the number of coins to move to/from the current node to balance it
    int dfs(TreeNode* node){
        if (node == NULL) return 0; // Base case: agar node null ho toh 0 coins ki zarurat

        // Left aur right subtree se required coins calculate karo
        int leftRequired = dfs(node->left);
        int rightRequired = dfs(node->right);   

        // Har move ka cost abs() me count hota hai, kyunki chahe coins left se right jaaye ya right se left, 
        // ek hi move count hoti hai
        steps += abs(leftRequired) + abs(rightRequired);
        
        /*
            Explanation of the return:
            - Har node ko 1 coin chahiye hota hai.
            - Agar node ke paas `val` coins hain, toh uske paas (val - 1) extra ya kam coins hain.

            - left aur right subtree se jo coins aaye/jaaye, 
            unko current node ke coins ke sath add karo.
            - Ye value parent node ko pass hoti hai, 
            jo batati hai ki current node ne kitne coins bheje ya liye.
            
        */

        return (node->val - 1) + leftRequired + rightRequired;

    }

    // Main function to initiate dfs and return total steps
    int distributeCoins(TreeNode* root) {

        dfs(root);

        return steps;
    }

};



/*

amount mere ko recursive call mai waapas aate waqt calculate karni hai.....so written post recursive call.....
time and space complexity of simple dfs i.e. O(n)

*/


/**
 * Definition for a binary tree node.
 
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 

 */


class Solution {
public: 

    // Function: distributeCoins
    // root: current node of the binary tree
    // parent: parent of the current node (NULL in case of root)

    // Task: Distribute the coins in such a way that every node has exactly 1 coin
    // Returns: Total number of moves required

    int distributeCoins(TreeNode* root, TreeNode* parent = NULL) {
        
        // Base case: Agar current node NULL hai to 0 moves lagenge
        if (root == NULL) return 0;

        // Recursive call: Left aur right subtree ko solve karo
        // Har call return karega us subtree ko balance karne ke liye required moves
        int moves = distributeCoins(root->left, root) + distributeCoins(root->right, root);

        // root->val - 1 ka matlab:
        // - Agar root->val > 1 hai, to is node ke paas extra coins hain -> x > 0
        // - Agar root->val < 1 hai, to is node ko coins chahiye -> x < 0
        // - Agar root->val == 1 hai, to is node ke paas perfect coins hain -> x = 0
        
        int x = root->val - 1;

        // Agar parent hai to:
        // - Extra coins ko parent node me push karo ya waha se pull karo
        // - x coins parent ke val me add kar diye jaate hain
        if (parent) parent->val += x;

        // Har move me ek coin ek edge ke across move hota hai
        // Isliye moves me abs(x) add karo (chahe coin aaye ya jaaye)
        moves += abs(x);

        // Total moves return karo is subtree ke liye
        return moves;
    }

};




/*
can we modify the given function in leetcode ? yes ofcourse here we will add parent node also...

The idea is that the child give x = (y-1) coins to parent, if he has y coins. 
(if y=0=> x=-1 then parent should give the child 1 coin)

Add an extra parameter TreeNode* parent= NULL instead of a helper function.

The number of moves comes from its left & right subtrees &
When x>0 is to give, when x<0 is to obtain. So moves += abs(x)


Why not Pre-Order? Why Post-order?

As the root of a subtree, it's unkown how many descendants it has before performing 
any kind of transversal. The thinking of parent-gives-coins-to-children will not work.

Use post-order transverals, because every node has a parent except for the root. 
It works that children give coins to parents.

*/