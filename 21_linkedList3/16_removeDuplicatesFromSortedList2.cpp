// removeDuplicatesFromSortedList2.cpp

/*

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.


Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]


Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/



#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.

struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; // Handle empty list

        // Map to store the frequency of each value
        map <int, int> mp;
        
        ListNode* temp = head;
        
        // Traverse the list and store frequency of each value
        while (temp != nullptr) {

            mp[temp->val]++;
            temp = temp->next;

        }
        
        // Create a dummy node to build the new list
        ListNode* dummy = new ListNode(-1);
        ListNode* newList = dummy;
        
        // Iterate through the map and add only unique elements to the new list
        for (auto& el : mp) {

            if (el.second == 1) {
                newList->next = new ListNode(el.first);
                newList = newList->next;
            }

        }
        
        return dummy->next; // Return the new list, skipping the dummy node
    }
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; // Handle empty or single-node lists

        ListNode* dummy = new ListNode(-1); // Dummy node to simplify handling the head
        dummy->next = head;

        ListNode* prev = dummy; // Pointer to track the last unique node
        ListNode* curr = head; // Pointer to traverse the list

        while (curr) {
            // Skip all nodes with the same value
            while (curr->next && curr->val == curr->next->val) {
                curr = curr->next;
            }

            if (prev->next == curr) {
                // No duplicates found for the current value
                prev = prev->next;
            } 
            
            else {
                // Duplicates found, skip them
                prev->next = curr->next;
            }

            // Move to the next node
            curr = curr->next; 
        }

        return dummy->next;
    }
};
