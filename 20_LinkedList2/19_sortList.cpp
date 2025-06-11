#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]


Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]


Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    // Helper function to merge two sorted linked lists into one sorted list.
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // Create a dummy node to act as the head of the new merged list.
        ListNode* dummy = new ListNode(0);
        // 'curr' is a pointer used to build the merged list.
        ListNode* curr = dummy;

        // Traverse both lists until one becomes NULL
        while (l1 != NULL && l2 != NULL) {
            // Compare current values and attach the smaller node to the merged list.
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;  // Move l1 forward
            } 
            
            else {
                curr->next = l2;
                l2 = l2->next;  // Move l2 forward
            }

            curr = curr->next;  // Move the current pointer forward
        }

        // If any elements remain in l1 or l2, attach them directly.
        if (l1 != NULL) curr->next = l1;
        else curr->next = l2;

        // Return the merged list, skipping the dummy node.
        return dummy->next;
    }

    // Main function to sort a linked list using merge sort.
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has one node, it is already sorted.
        if (head == NULL || head->next == NULL) return head;

        // Use slow and fast pointers to find the midpoint of the list.
        ListNode* slow = head;
        ListNode* fast = head->next; // yaha bkl fast ko ek aage se kyu initalise kiya ?? Race to BC starting point se hoti thi na...

        // Move fast by two and slow by one to find the middle.
        // When fast reaches the end, slow will be at the middle.
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves at the middle.
        ListNode* mid = slow->next;  // Start of second half
        slow->next = NULL;           // Break the list into two

        // Recursively sort both halves.
        ListNode* left = sortList(head);   // Sort left half
        ListNode* right = sortList(mid);   // Sort right half (abey ha saale kisi bhi list ka starting point hi to pass karte h..)

        // Merge the two sorted halves.
        return merge(left, right);
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
class Solution{
public:
    ListNode* array2LL(vector <int> &v){
        ListNode* head = new ListNode(v[0]);
        ListNode* mover = head;
        for (int i=1; i<v.size(); i++){
            ListNode* temp = new ListNode(v[i]);
            mover->next = temp;
            mover = mover->next;
        }
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        vector <int> v;
        while (head!=NULL){
            v.push_back(head->val);     // ordering important..
            head = head->next;     
        }

        sort(v.begin() , v.end());
        return array2LL(v);
    }
};


// size of ll
// array sort and make it ll..