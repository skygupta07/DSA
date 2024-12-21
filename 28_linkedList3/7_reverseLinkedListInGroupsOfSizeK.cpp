#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Helper function to reverse a sublist between two pointers
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* current = start;
        ListNode* nextNode;

        // Reverse nodes until 'end'
        while (current != end) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev; // New head of the reversed sublist
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0); // Dummy node to simplify handling the head
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (head) {
            // Find the end of the current group
            ListNode* groupEnd = head;
            for (int i = 1; i < k && groupEnd; ++i) {
                groupEnd = groupEnd->next;
            }

            // If fewer than k nodes remain, do not reverse
            if (!groupEnd) break;

            // Save the next group's start
            ListNode* nextGroupStart = groupEnd->next;

            // Reverse the current group
            groupEnd->next = NULL; // Temporarily break the chain
            ListNode* newGroupStart = reverseList(head, NULL);

            // Reconnect the reversed group with the rest of the list
            prevGroupEnd->next = newGroupStart;
            head->next = nextGroupStart;

            // Move pointers to the next group
            prevGroupEnd = head;
            head = nextGroupStart;
        }

        return dummy->next;
    }
};
