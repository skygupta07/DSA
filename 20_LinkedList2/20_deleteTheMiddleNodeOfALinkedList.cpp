// deleteTheMiddleNodeOfALinkedList.cpp

/*

You are given the head of a linked list. Delete the middle node, 
and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
 

Example 1:

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 


Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.


Example 3:

Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
 


Constraints:

The number of nodes in the list is in the range [1, 10pow5].
1 <= Node.val <= 10pow5

*/




#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: single node list
        if (head == NULL || head->next == NULL) return NULL;

        // First, find the length of the linked list
        int len = 0;

        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        // Middle index (0-based) - yes this gem handles both case wisely..
        int middle = len / 2;

        // Traverse again to node just before the middle (ha bhai jaha tak karna hota h wahi loop mai likh dete h...
        // for (alpha = start; alpha < jaha tak jaana h ; alpha++))

        temp = head;
        for (int i = 0; i < middle - 1; i++) {
            temp = temp->next;
        }

        // Delete the middle node
        ListNode* nodeToDelete = temp->next;

        temp->next = temp->next->next;

        delete nodeToDelete; // Free memory (important in interviews and practice)

        return head;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;

        ListNode* prev;

        // starting race from same point
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            prev = slow;

            slow = slow->next;
            fast = fast->next->next;
        }

        // here prev is one behind slow , slow is at middle and fast is at end of ll

        prev->next = slow->next;
        delete slow;

        return head;
    }
};

/*
when fast reaches end , slow reaches middle
*/

