// partitionList.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given the head of a linked list and a value x, 
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]


Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

*/


class ListNode{
public:

    int val;
    ListNode* next;


    ListNode(int v){ // constructor
        this->val = v;
        this->next = NULL; // by default jitne bhi nodes banenge unke next wale section me NULL pointer lag jaega..
    }

};



class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for two separate lists:

        // 'before' will hold nodes with values < x
        // 'after' will hold nodes with values >= x

        ListNode before(0);  // dummy node for the 'before' list
        ListNode after(0);   // dummy node for the 'after' list
        

        // Pointers to the current end of the 'before' and 'after' lists
        ListNode* beforeCurr = &before;
        ListNode* afterCurr = &after;


        // Traverse the original list
        while (head) {

            if (head->val < x) {
                // Append to the 'before' list
                beforeCurr->next = head;  // connect current node to 'before' list
                beforeCurr = head;        // move 'before' pointer forward
            } 
            
            else {
                // Append to the 'after' list
                afterCurr->next = head;   // connect current node to 'after' list
                afterCurr = head;         // move 'after' pointer forward
            }

            head = head->next;  // move to next node in original list
        }

        // Now the last node of 'after' list should point to NULL
        afterCurr->next = NULL;

        // Link the end of 'before' list to the head of 'after' list
        beforeCurr->next = after.next;

        // Return the new head of the rearranged list (skipping dummy node)
        return before.next;
    }
};
