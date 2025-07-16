// reverseLinkedList.cpp

/*

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. 
Could you implement both?

*/

#include <bits/stdc++.h>
using namespace std;

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


    // just remember it .. yes i have understood it...
    // Function to reverse a singly linked list


    // abey bkl jab tu vector ko do pointers ki help se reverse kar leta h... to abey saale ll ko to tu 
    // aaram se do pointer se reverse kar lega...sach mai deep mai socho to nahi... coz yrr tu head ka bhi 
    // to use le hi raha h... to wo bhi to ek tarah se count hoga hi...

    // matlab mai ek tarah se theek hi soch raha tha ... ki bhai teen pointer use honge... prev, curr, next..
    // ab yaha wo curr ka kaam head ne help karwa di....

    ListNode* reverseList(ListNode* head) {
        // Initialize previous node as NULL (end of reversed list)
        ListNode* prev = nullptr;
        
        // Pointer to hold the next node temporarily during traversal
        ListNode* next = nullptr;

        // Traverse the linked list using head pointer itself...{aur ab jab head se hi traverse kar rahe h
        // to bhaiya constraint bhi to head pe hi lagega...
        // {nhph kardo bas simple...}

        while (head != nullptr) {
            // Store next node before breaking the link
            next = head->next; // left will point to right 
            // Reverse the curr node's pointer
            head->next = prev; // head ka next previous pe jaega...

            // Move prev and head one step forward
            prev = head; // prev will point or you can say will move to head 
            head = next; // head will point to next
        }

        // At the end, prev will be the new head
        return prev;
    }

};


// using recursion, tc O(n), sc O(n)
// recursion wala samjha ke dikhao....

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        // Base Case: agar list khali hai ya sirf ek node hai
        // toh wahi head hi reversed list ka head hoga {zero or one node case -> my favourite line}
        if (head == NULL || head->next == NULL) return head;

        // Recursive Call:
        // Har call mein head ke next wale node ke aage reverse karte jao,
        // jab tak end tak na pahuch jaaye (i.e., head->next becomes NULL)
        ListNode* newHead = reverseList(head->next);

        // Ab yahan se actual reverse karna start hoga:
        // Suppose list abhi aisi hai: head -> next -> ... -> NULL
        // Toh hume karna hai: next->next = head
        // yani jo next node hai, uska next ab head ban jaaye
        head->next->next = head;

        // Ab head ka next NULL karna zaroori hai
        // warna last do nodes ke beech circular reference ban jaayega
        head->next = NULL;

        // Har recursion step mein newHead same rahega (end node)
        // Usko return karte jaayenge upar tak
        return newHead;
    }
};

// bhadwa approach
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Step 1: Vector banate hain list ke saare nodes ko store karne ke liye
        // yes bro vector can store any kind of data type ...
        vector <ListNode*> nodes;

        // curr pointer se list ko traverse karenge
        ListNode* curr = head;

        // Jab tak curr NULL nahi hota, tab tak vector me node daalte jao
        while (curr != nullptr) {
            nodes.push_back(curr);
            curr = curr->next;
        }

        // Total nodes kitne hain list me
        int n = nodes.size();

        // Dummy node banate hain, jisse reversal process easy ho jaye
        ListNode* dummy = new ListNode(-1);
        ListNode* iterator = dummy; // Ye actual list build karega

        // Step 2: Vector ko ulta loop karte hain (last se first tak)
        for (int i = n - 1; i >= 0; i--) {
            ListNode* currNode = nodes[i]; // curr node uthayi

            iterator->next = currNode;     // Usko dummy list me add kiya
            iterator = iterator->next;        // Iterator ko aage badhaya
        }

        // Step 3: Last node ka next NULL set karna mat bhoolna
        // Warna purani list ke pointer se cycle ban sakta hai
        iterator->next = nullptr;

        // Step 4: Dummy node ke next me actual reversed list ka head hai
        return dummy->next;
    }
};
