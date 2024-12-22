#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;   // imp

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            
            ans.push_back(node->val);
            // Push all the children of the current node onto the stack
            for (auto child : node->children) {
                st.push(child);
            }
        }

        // Reverse the result to get the correct postorder traversal

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*


# Intuition
The problem can be solved using recursion, but using a stack can help simulate the recursive approach iteratively.

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
    void f(Node* &root, vector <int> &ans){
        if (root == NULL) return;

        for (auto child : root->children){
            f(child, ans);
            ans.push_back(child->val);
        }
    }



public:
    vector<int> postorder(Node* root) {
        vector <int> ans;
        f(root, ans);
        if (root != NULL) ans.push_back(root->val);
        return ans;
    }
};