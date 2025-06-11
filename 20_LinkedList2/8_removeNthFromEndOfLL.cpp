// removeNthNodeFromEndOfLL.cpp

#include <bits/stdc++.h>
using namespace std;


/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

struct ListNode {
    int val;
    ListNode *next;

    // Constructor to initialize a new node with a value and set next to NULL
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Create a dummy node and point it to the head.
        // This dummy node helps handle edge cases easily (like deleting the head node).
        ListNode* temp = new ListNode(-1);
        temp->next = head;

        // Step 2: Initialize two pointers, both starting from the dummy node.
        ListNode* slow = temp;
        ListNode* fast = temp;

        // Step 3: Move the `fast` pointer n steps ahead.
        // After this loop, the gap between `fast` and `slow` is n nodes.
        for(int i = 1; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4: Move both `fast` and `slow` one step at a time until `fast` reaches the last node.
        // At that point, `slow` will be pointing to the node **just before** the node we want to delete.
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5: Delete the node after `slow` (which is the nth node from the end).
        ListNode* nodeToDelete = slow->next;           // Store the node to delete.
        slow->next = slow->next->next;                 // Skip the node to be deleted.
        delete(nodeToDelete);                          // Free memory to prevent memory leak.

        // Step 6: Return the new head of the list (might be different if the head was deleted).
        return temp->next;     // Skip dummy node and return the actual head.

        // Note: No need to delete `temp` because it's not dynamically linked in the list; it's just used as a helper.
    }
};


// maintain two pointers and update one with a delay of n steps....


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // khali ya ek hi node mai delete karega to pura khalaas..
        if (head == NULL || head->next == NULL) return NULL;

        int len = 0;
        ListNode* temp = head;

        // Step 1: Count the length
        while (temp) {
            len++;
            temp = temp->next;
        }

        // Special case: deleting the first node - head hi delete ho jayega to linked list kaise return karoge..
        // so please handle it carefully...
        if (n == len) {
            ListNode* nodeToDelete = head;
            head = head->next;

            delete nodeToDelete;
            return head;
        }

        // Step 2: Go to the node just before the one to delete
        temp = head;
        for (int i = 0; i < len - n - 1; i++) {
            temp = temp->next;
        }

        // Step 3: Delete the nth node from end
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;

        delete nodeToDelete;

        return head;
    }
};
