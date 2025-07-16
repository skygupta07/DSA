// findFirstNodeOfLoop.cpp

/*

Given a head of the singly linked list. If a loop is present in the list then return 
the first node of the loop else return NULL.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node 
to which the last node points to. If pos = 0, it means the last node points to null, 
indicating there is no loop.

Examples:

Input:
 
Output: 3

Explanation: We can see that there exists a loop in the given linked list and the first node 
of the loop is 3.

Input:
 
Output: -1


Explanation: No loop exists in the above linked list.So the output is -1.
Constraints:
1 <= no. of nodes <= 1e6
1 <= node->data <= 1e6 

*/


#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
public:

    Node* findFirstNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if a cycle exists using two pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) break;
        }

        // If no cycle, return -1
        if (!fast || !fast->next) return NULL;
        

        // Step 2: Find the first node of the loop
        slow = head; // Reset slow to the head
        
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // The node where slow and fast meet is the start of the loop
        return slow;
    }
};
