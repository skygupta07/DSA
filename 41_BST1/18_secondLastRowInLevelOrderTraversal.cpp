#include <bits/stdc++.h>
using namespace std;

// Node class to create Binary Search Tree nodes
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> postorder(n);
    for (int i = 0; i < n; i++) cin >> postorder[i];

    // Step 1: Construct BST from postorder traversal
    Node* root = new Node(postorder[n - 1]);  // Last element is the root
    stack<Node*> buildStk;
    
    buildStk.push(root);

    for (int i = n - 2; i >= 0; i--) {
        Node* node = new Node(postorder[i]);
        Node* curr = buildStk.top();

        if (postorder[i] > curr->data) {
            // Right child of current node
            curr->right = node;
        } 
        else {
            // Find correct parent for left child
            while (!buildStk.empty() && postorder[i] < buildStk.top()->data) {
                curr = buildStk.top();
                buildStk.pop();
            }
            curr->left = node;
        }
        buildStk.push(node);
    }

    // Step 2: Level order traversal and store each level
    queue<Node*> q;
    q.push(root);

    stack <vector <int>> levels; // Stack to store each level bottom-to-top

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        while (size-- > 0) {
            Node* curr = q.front();
            q.pop();

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);

            level.push_back(curr->data);
        }

        levels.push(level);  // Push current level to stack
    }

    // Step 3: Pop last level (bottom-most level)
    if (!levels.empty()) levels.pop();

    // Step 4: Print second-last level
    if (!levels.empty()) {
        vector<int> ans = levels.top();
        for (int val : ans) {
            cout << val << " ";
        }
    } 
    
    else cout << "No second-last level exists";

    return 0;
}
