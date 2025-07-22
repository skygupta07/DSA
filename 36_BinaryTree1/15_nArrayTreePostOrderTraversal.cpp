// nArrayPostOrderTraversal.cpp {easy marked}

#include <bits/stdc++.h>
using namespace std;

/*

Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal.
Each group of children is separated by the null value (See examples)
 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]


Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 


Constraints:

The number of nodes in the tree is in the range [0, 1e4].
0 <= Node.val <= 1e4
The height of the n-ary tree is less than or equal to 1000.
 

Follow up: Recursive solution is trivial, could you do it iteratively?

*/


// Definition for a Node.
class Node {
public:

    int val;
    vector <Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector <Node*> _children) {
        val = _val;
        children = _children;
    }
};


// dry run done
class Solution {
public:

    vector <int> postorder(Node* root) {
        vector<int> ans;

        if (root == NULL) return ans;   // nalla case

        stack <Node*> stk;
        stk.push(root);

        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            
            ans.push_back(node->val);
            
            // Push all the children of the current node onto the stack
            for (auto child : node->children) {
                stk.push(child);
            }
        }

        // Reverse the result to get the correct postorder traversal

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*


# Intuition
The problem can be solved using recursion, 
but using a stack can help simulate the recursive approach iteratively.

# Approach
1. Use a stack to simulate the recursive process.
2. Start by pushing the root node onto the stack.
3. Pop elements from the stack, and push them onto the result vector.
4. Push the children of the current node onto the stack to ensure they are processed.
5. Finally, reverse the result vector to achieve postorder traversal.

# Complexity
- Time complexity: 
O(n), where 'n' is the number of nodes in the tree. Each node is processed once.

- Space complexity:
O(n), due to the stack used to store nodes.

# Code

*/


// ------

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private: 

    void solve(Node* &root, vector <int> &ans){
        if (root == NULL) return;

        for (auto child : root->children){

            // ab iss call ke liye to child will behave like root
            solve(child, ans);

            ans.push_back(child->val);
        }
    }


public:

    vector <int> postorder(Node* root) {
        vector <int> ans;

        solve(root, ans);

        if (root != NULL) ans.push_back(root->val);

        return ans;
    }

};