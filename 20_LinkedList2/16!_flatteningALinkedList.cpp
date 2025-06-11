// flatteningALinkedList.cpp

/*

Given a linked list containing n head nodes where every node in the linked list contains two pointers:

(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.

Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level 
while maintaining the sorted order.


Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5-> 7-> 8-> 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.


Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.


Constraints:
0 <= n <= 100
1 <= number of nodes in sub-linked list(mi) <= 50
1 <= node->data <= 10pow4

*/



#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};


class Solution{
public:

        Node* flatten(Node* root) {
            if (!root) return nullptr;
            
            // Collect all values
            vector <int> values;
            Node* current = root;

            while (current) {
                Node* down = current;

                while (down) {
                    values.push_back(down->data);
                    
                    Node* to_delete = down;  // Store for deletion
                    down = down->bottom;
                    delete to_delete;      // Free memory
                }

                current = current->next;
            }
            
            // Sort the values
            sort(values.begin(), values.end());
            
            // Rebuild the flattened list using bottom pointers
            Node* dummy = new Node(-1);
            Node* tail = dummy;
            
            for (int val : values) {
                tail->bottom = new Node(val);
                tail = tail->bottom;
            }
            
            Node* result = dummy->bottom;
            
            delete dummy;  // Delete the temporary dummy node
            return result;
        }

};