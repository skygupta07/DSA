#include <bits/stdc++.h>
using namespace std;

/*

Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (
i.e., only nodes themselves may be changed.)
 

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Explanation:

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]

Example 4:

Input: head = [1,2,3]
Output: [2,1,3]


Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {

         // Base case: less than two nodes
        //  or if (head == NULL || head->next == NULL) return head;
        if (!head || !head->next) return head;
        
        // Dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0); // create dummy
        dummy->next = head; // attach dummy

        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swapping nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move `prev` to the next pair
            prev = first;
        }

        return dummy->next;
    }
};
