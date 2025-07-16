// rotateALinkedListKTimesLeftSideIMP.cpp

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};


class Solution {
public:

    // Function to rotate the linked list by k positions
    Node* rotate(Node* head, int k) {
        // Edge case: if list is empty or k is 0, return the head as is
        if (!head || k == 0) return head;

        // Step 1: Compute the length of the linked list
        int length = 1;  // Start with 1 to include the head
        
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make the linked list circular
        tail->next = head;

        // Step 3: Normalize k (if k >= length, rotation repeats)
        k = k % length;
        if (k == 0) {
            // No rotation needed, break the circular connection and return original head
            tail->next = nullptr;
            return head;
        }

        // Step 4: Find the new tail (node at position length - k - 1)
        int stepsToNewTail = length - k;
        
        Node* newTail = head;
        for (int i = 1; i < stepsToNewTail; ++i) {
            newTail = newTail->next;
        }

        // Step 5: Set new head and break the circle
        Node* newHead = newTail->next;
        newTail->next = nullptr;

        // Step 6: Return the new head of the rotated list
        return newHead;
    }
};
