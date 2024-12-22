/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next; // definition hi thodi badal rakhi h... ye khud allow kar rha h next lagane ke liye .. to kyu na lagaye..

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
         
        if (root -> left ) root -> left -> next = root -> right;
        if (root -> right && root -> next) root -> right -> next = root -> next -> left;

        connect (root -> left);
        connect (root -> right);

        return root;
    }
};

// Initially, all next pointers are set to NULL -> sahi h...



-----

class Solution {
public:
    Node* connect(Node* root) {
        // Pointer to traverse the previous level (starting at the root)
        Node* prev = root;
        Node* curr; // Pointer to traverse the current level

        // Iterate through levels of the binary tree
        while (prev) { // Continue as long as there are levels to process
            curr = prev; // Start traversal of the current level from `prev`

            // Traverse all nodes at the current level
            while (curr && curr->left) { // Only process nodes that have children
                // Connect the left child to the right child
                curr->left->next = curr->right;

                // If the current node has a `next` pointer, connect the current node's
                // right child to the left child of the next node
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                // Move to the next node at the current level
                curr = curr->next;
            }

            // Move down to the next level (leftmost child of the current level)
            prev = prev->left;
        }

        // Return the modified tree with populated `next` pointers
        return root;
    }
};
