// reorderList.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]


Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 1e4].
1 <= Node.val <= 1000

*/


struct ListNode {
      int val;
      ListNode *next;
      
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    void reorderList(ListNode* head) {
        // Step 1: Find middle of the list using slow and fast pointer
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;           
            fast = fast->next->next;    
        }

        // Ab slow middle node pe aagaya hai
        // Step 2: Reverse the second half of the list starting from slow

        ListNode* p = NULL;   // p: previous node
        ListNode* q = slow;   // q: current node
        
        ListNode* r = slow->next; // r: next node (initially)

        while (q != NULL){
            r = q->next;      // save next
            q->next = p;      // reverse current node pointer
            
            p = q;            // move p ahead
            q = r;            // move q ahead
        }

        // Step 3: Merge first half and reversed second half
        ListNode* head1 = head;   // Pointer for first half
        ListNode* head2 = p;      // Pointer for reversed second half (p is head of reversed)


        while (head2->next != NULL){
            // Save next node of first half
            ListNode* temp = head1->next;

            head1->next = head2;  // point current first half node to one node from second half
            head1 = temp;         // move head1 to next

            // Save next node of second half
            temp = head2->next;

            head2->next = head1;  // point current second half node to next node of first half
            head2 = temp;         // move head2 to next
        }
    }
};
