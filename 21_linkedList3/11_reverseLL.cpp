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




/*
Given the head of a singly linked list, reverse the list,
and return the reversed list.
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL){
            ListNode* currNext = curr->next;
            curr->next = prev;

            prev = curr;
            curr = currNext;
        }
        return prev;
        
    }
};

// ----recursive soln---------

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);    // head ka next next karte ja jab tak end na mil jae..

        (head->next)->next = head;        // (head->next)->next = head;
        head->next = NULL;      // ekdum last wale node ke liye helpful taki last ki do nodes mai cycle na ban jaye..

        return newHead;
    }
};



/*
linked list mai left = right ka matlab hota hai...
left mai jo bhi hai POINTS TO right mai jo bhi hai..
*/


// --- noob approach -=-------


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Vector to store the nodes of the list
        vector<ListNode*> nodes;

        // Pointer to traverse the list
        ListNode* current = head;

        // Traverse the list and store each node in the vector
        while (current != nullptr) {
            nodes.push_back(current);
            current = current->next;
        }

        // Get the number of nodes in the list
        int n = nodes.size();

        // Create a dummy node to simplify the reversal process
        ListNode* dummy = new ListNode(-1);
        ListNode* iterator = dummy;

        // Iterate over the vector in reverse order to rebuild the list
        for (int i = n - 1; i >= 0; i--) {
            ListNode* currentNode = nodes[i];
            dummy->next = currentNode;
            dummy = dummy->next;
        }

        // Set the next of the last node to null to terminate the reversed list
        dummy->next = nullptr;

        // Return the head of the reversed list
        return iterator->next;
    }
};






