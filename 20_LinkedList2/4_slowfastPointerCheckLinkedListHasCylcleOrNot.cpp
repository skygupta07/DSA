#include <bits/stdc++.h>
using namespace std;

/*

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again 
by continuously following the next pointer. 

Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.


Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 10pow4].
-10pow5 <= Node.val <= 10pow5

pos is -1 or a valid index in the linked-list.
 
Follow up: Can you solve it using O(1) (i.e. constant) memory?

*/

// Definition for singly-linked list.
struct ListNode {
      int val;

      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:

    bool hasCycle(ListNode *head) {
        
        ListNode* slow = head;  // tortoise and hare both at starting line
        ListNode* fast = head;  // slow and fast pointer...

        // constraint to faast par hi hai...wahi tej baagh raha hai...
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // har moment pe check kara ... increment karne ke baad ki agar wo 
            // same jagah point karne lage hai...=> there was loop somewher...
            if (slow == fast ) return true;
        } 

        return false;
    }
};

/*

while loop ke andar agar aapki pehli hi condition false ho gayi to wo andar ki next condition 
check nahi karta ...isliye yaha par hum bach jaenge...aur NULL->next nahi nikal rahe honge...

*/