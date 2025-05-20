// verticalOrderTraversalOfBinaryTree.cpp

#include <bits/stdc++.h>
using namespace std;


class TreeNode{ 
public:
    // val members
    int val;    // data or val
    TreeNode *left, *right; // asked in interview..

    // constructors with varying use...(constructor overloading)
    TreeNode(){
        this->val = 0;
        left = NULL;
    }
    TreeNode(int val){
        this->val = val; 
        this->left = NULL;
        this->right = NULL;
    }
    TreeNode(int val, TreeNode* left, TreeNode* right){
        this->val = val;
        this->left = left;
        this->right = right;
    }
};


class Solution {
public:
    vector <vector <int> > verticalTraversal(TreeNode* root) {
        // Map to hold mp by their vertical and horizontal distances:
        // map<int, map<int, multiset<int>>>
        //  - First int: Vertical distance from the root (x-coordinate)
        //  - Second int: Horizontal distance (level) from the root (y-coordinate)
        //  - multiset<int>: To store node values at the same position (x, y)
        map <int, map <int, multiset <int>>> mp;

        // Queue to perform level order traversal (BFS).
        // Each element in the queue is a pair:
        //  - First: The current node
        //  - Second: A pair of integers (x, y) representing the node's position.
        queue <pair <TreeNode*, pair<int, int>>> q;

        // Start BFS with the root node at position (0, 0)
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();  // Get the front element in the queue
            q.pop();
            
            TreeNode* node = p.first;  // Current node
            int x = p.second.first;    // Vertical distance
            int y = p.second.second;   // Horizontal distance

            // Insert the node's value into the map at position (x, y)
            mp[x][y].insert(node->val);

            // If the node has a left child, push it into the queue with updated position
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }

            // If the node has a right child, push it into the queue with updated position
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        // Prepare the result vector from the map  mp'
        vector <vector <int>> result;

        // Traverse the map  'mp' by vertical levels
        for (auto p : mp) {
            vector <int> col;  // Vector to store mp in the current vertical level
            
            for (auto q : p.second) {
                // Insert all mp at the same vertical and horizontal position into 'col'
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the current vertical level to the result
            result.push_back(col);
        }

        return result;  // Return the final result
    }
};
