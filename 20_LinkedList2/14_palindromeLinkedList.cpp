// palindromeLinkedList.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given the head of a singly linked list, 
return true if it is a palindrome or false otherwise.


*/


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

//  using vector
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            int n = 0;
            vector <int> v;
    
            ListNode* temp = head;
    
            while (temp != NULL){
                v.push_back(temp->val);
                n++;
                temp = temp ->next;
            }
    
            int left = 0;
            int right = n - 1;
    
            while (left < right){
                if (v[left] != v[right]) return false;
                left++;
                right--;
            }
    
            return true;
    
    
        }
    };
    
    /*
    create vector from linkedlist and see if it is palindrom or not ?
    
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
    
        // Ye function linked list ko reverse karne ka kaam karega
        ListNode* reverse(ListNode* head){
            // prev, curr aur next pointer hai aur sab kucch sequence mai hi h..
            ListNode* prev = NULL; // Pehle koi node nahi h, to prev NULL hoga
            ListNode* curr = head; // Current pointer ko head pe rakha
    
            while (curr != NULL){  // Jab tak list khatam nahi hoti, loop chalayenge
                ListNode* next = curr->next; // Next node ko store kar liya
                curr->next = prev;  // Current node ka next ko piche point kar diya
                prev = curr; // Prev ko ek step aage badhaya
                curr = next; // Curr ko next node pe shift kiya
            }
    
            return prev; // Naya head jo reverse list ka h, return kar diya
        }
    
        // Ye function check karega ki given linked list palindrome h ya nahi
        bool isPalindrome(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
    
            // Pehle slow-fast pointer technique se middle node tak pohchna h
            while (fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            // Slow pointer ab middle pe hoga
            ListNode* rev = reverse(slow); // Second half ko reverse kar diya
    
            // Ab dono halves ka comparison karenge
            while (rev != NULL){
                if (head->val != rev->val) return false; // Agar koi bhi mismatch milta h to palindrome nahi h
                head = head->next; // First half ko aage badha rahe h
                rev = rev->next; // Reversed second half ko bhi aage badha rahe h
            }
    
            return true; // Agar pura match ho gaya to palindrome h
        }
    };
    