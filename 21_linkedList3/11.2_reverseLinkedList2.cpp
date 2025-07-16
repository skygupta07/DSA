// reverseLinkedList2.cpp

/*

Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.
 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4

Output: [1,4,3,2,5]


Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.

1 <= n <= 500
-500 <= Node.val <= 500

1 <= left <= right <= n

Follow up: Could you do it in one pass?

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

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        // Create a dummy node to simplify edge cases (e.g., reversing from head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // `prev` will eventually point to the node before the sublist to be reversed
        ListNode* prev = dummy;

        // Move `prev` to the (m-1)th node
        for (int i = 0; i < m - 1; i++) {
            prev = prev->next;
        }

        // `curr` is the first node of the sublist to be reversed
        ListNode* curr = prev->next;

        // Perform front insertion for (n - m) steps
        for (int i = 0; i < n - m; i++) {
            // Temporarily store the node to be moved {sequential flow ki tarah yaad karna padega.. 
            // right wali cheej aage wali ki left wali ban jaa rahi h ...}
            // aur jaise swap karne wale ka intuitiveness bhi aa rha h...
            ListNode* temp = curr->next;

            // Adjust links to "remove" temp from its currrent position
            curr->next = temp->next;

            // Insert temp after prev
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;
    }
};


/*

Use a dummy node to simplify pointer manipulation, especially if the head is part of the reversal range.

Move prev to the node before the reversal starts.
Use a head insertion approach:
Each time, take the node after curr and insert it right after prev.
Do this n - m times ->> this reverses the sublist.

*/