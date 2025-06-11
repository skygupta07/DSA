// linkedListCycle2.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the head of a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be 
reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected 
to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.
*/

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
     ListNode* detectCycle(ListNode* head) {
       // Initialize two pointers, slow and fast, to the head of the linked list.
       ListNode* slow = head;
       ListNode* fast = head;
   
       // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
       // until they either meet or the fast pointer reaches the end of the list.
       while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;

          if (slow == fast) {
              // If the pointers meet, there is a cycle in the linked list.
              // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
              // until they meet again. The node where they meet is the starting point of the cycle.
              slow = head; // importantwa..

              while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
              }

              return slow;
          }
        }
   
       // If the fast pointer reaches the end of the list without meeting the slow pointer,
       // there is no cycle in the linked list. Return nullptr.
       return nullptr;
     }
   };
   
   /*
   Distance from head to start of cycle = Distance from meeting point of slow and fast to the start of cycle
   
   */