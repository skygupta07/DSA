// reverseNodesInKGroup.cpp

/*

Given the head of a linked list, reverse the nodes of the list k at a time, 
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

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

    // Helper function: Reverse the linked list from start till 'end' (exclusive)
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = NULL;
        ListNode* current = start;
        ListNode* nextNode = NULL;

        // Jab tak current 'end' tak nahi pahuchta, reverse karte jao - 
        // {reverse karna matlab nhph karna...} yaha h yaahi head ki jagah curr se denote kar rahe h...
       
        while (current != end) {
            nextNode = current->next;   // Next node store karo
            current->next = prev;       // Current ka next ulta kar do

            prev = current;             // Prev ko aage badhao
            current = nextNode;         // Current ko aage badhao
        }

        // Jab loop khatam ho, prev nayi reversed list ka head hota hai
        return prev;
    }


    // Main function: Reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Edge case: agar list khali hai ya k == 1 hai, toh no need to reverse
        if (!head || k == 1) return head;

        // Dummy node banate hain to handle head reversal easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head; // this line is always followed by the dummy node creation...

        ListNode* prevGroupEnd = dummy; // Ye har group ke last node pe point karega

        while (head != NULL) {
            // Step 1: k size ka group dhoondo
            ListNode* groupEnd = head;

            for (int i = 1; i < k && groupEnd != NULL; i++) {
                groupEnd = groupEnd->next;
            }

            // Agar remaining nodes < k hain, toh reverse mat karo
            if (groupEnd == NULL) break;

            // Step 2: Group ka next node store kar lo (jahan se agla group start hoga)
            ListNode* nextGroupStart = groupEnd->next;

            // Step 3: Group ko temporarily tod do (taaki reverse kar sakein)
            groupEnd->next = NULL;

            // Step 4: Reverse current group
            ListNode* newGroupStart = reverseList(head, NULL);

            // Step 5: Previous group ke end ko is naye reversed group se jodo
            prevGroupEnd->next = newGroupStart;

            // Step 6: Ab head pura reverse ho chuka hai, wo group ka last node ban gaya h
            // Use next group ke first node se jod do
            head->next = nextGroupStart;

            // Step 7: prevGroupEnd aur head ko update karo next group ke liye
            prevGroupEnd = head;
            head = nextGroupStart;

        }

        // Final answer dummy->next pe milega, because dummy ke baad hi list start hui thi
        return dummy->next;
        
    }
};

