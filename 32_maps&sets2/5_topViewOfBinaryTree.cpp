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
        vector <int> ans;

        if (!root) return ans;

        // Map to store the first node at each horizontal distance
        // map's key -> horizontal distance,   map's value -> node->value
        // iss horizontal distance pe iss node ki value h...
        map <int, int> topNodeMap;


        // Queue to perform BFS (tu kucch bhi karle queue mai to pehla by default tere ko 
        // Node hi rakhna padega...)
        // TreeNode , horizontal distance ka pair..
        queue <pair <Node*, int>> q;

        // Start BFS from the root with horizontal distance 0 -> threshold
        q.push({root, 0});

        //bfs
        while (!q.empty()){
            pair <Node*, int> curr = q.front(); // or auto curr = q.front();
            q.pop();

            Node* node = curr.first;
            int hd = curr.second; 

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


/*

top view
bfs
mp <TreeNode*, horizontalDistance>

hd - 1 , hd + 1

*/