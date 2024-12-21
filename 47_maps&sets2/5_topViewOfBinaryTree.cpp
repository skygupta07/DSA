#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    // ek type ka constructor hi hai....
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        // Map to store the first node at each horizontal distance
        // map's key -> horizontal distance,   map's value -> node->value
        map<int, int> topNodeMap;


        // Queue to perform BFS
        // TreeNode , horizontal distance     ka pair..
        queue<pair<Node*, int>> q;

        // Start BFS from the root with horizontal distance 0 -> threshold
        q.push({root, 0});

        //bfs
        while (!q.empty()) {
            pair<Node*, int> front = q.front(); 
            Node* node = front.first;
            int hd = front.second;
            q.pop();

            // If this horizontal distance is being visited for the first time
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = node->data;
            }

            // Move to the left child
            if (node->left) q.push({node->left, hd - 1});

            // Move to the right child
            if (node->right) q.push({node->right, hd + 1});
        }

        // Extract the top view nodes from the map
        for (auto it : topNodeMap) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Node* root = new Node(1);   // dynamically allocating memory from heap
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.topView(root);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
