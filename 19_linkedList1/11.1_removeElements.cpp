#include <bits/stdc++.h>
using namespace std;


//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* removeElements(ListNode* head, int target) {
        // Dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* curr = head;
        ListNode* prev = dummy;

        while (curr != NULL) {
            if (curr->val == target) {
                prev->next = curr->next; // Skip current node
                delete curr; // Free memory
                curr = prev->next; // Move to the next node
            } else {
                prev = curr; // Move prev forward
                curr = curr->next; // Move curr forward
            }
        }
        
        head = dummy->next; // Update head in case first node was removed
        delete dummy; // Free dummy node
        return head;
    }
};
