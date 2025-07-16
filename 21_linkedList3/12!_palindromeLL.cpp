// palindromeLinkedList.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:


Input: head = [1,2,2,1]
Output: true


Example 2:

Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

*/


struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // oh bhai ye dekh dhyan se dekh dekh dhyan se {wo gangs of waseypur wala...} abey saala yaha 
        // base aur edge case mai ab antar samajh aa rha h...
        // base case compulsory to write in case of recursion...
        

        // Edge Case: Agar list empty hai ya sirf ek element hai, toh wo palindrome hi hogi.
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Reverse copy of the linked list banao
        ListNode* revHead = NULL;   // Reverse list ka head
        ListNode* ptr = head;      // Original list ke traversal ke liye

        while (ptr != NULL) {
            // Har node ka ek naya copy banake usko reverse list me daalo

            ListNode* temp = new ListNode(ptr->val); // Copy node
            temp->next = revHead;  // Insert at head of reversed list

            revHead = temp;        // Move reverse head to new node
            ptr = ptr->next;      // Move to next in original list
        }

        // Step 2: Compare original list and reversed list
        ListNode* p1 = head;
        ListNode* p2 = revHead;

        while (p1 && p2) {
            if (p1->val != p2->val) {
                return false;  // Agar koi value match nahi hui, palindrome nahi hai
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        // Agar pura traverse ho gaya bina mismatch ke, toh palindrome hai
        return true;
    }
};
