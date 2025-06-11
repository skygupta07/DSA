// linkedListRandomNode.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a singly linked list, return a random node's value from the linked list. 
Each node must have the same probability of being chosen.

Implement the Solution class:

Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value.
All the nodes of the list should be equally likely to be chosen.

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
private:
        ListNode* head; // Store the head pointer
        int size;       // Store the size of the linked list
    
public:

        Solution(ListNode* head) {
            this->head = head; // Store head pointer
            size = 0;
    
            ListNode* temp = head;
    
            // Calculate the size of the linked list
            while (temp) {
                size++;
                temp = temp->next;
            }
    
            srand(time(0)); // Seed random generator (to avoid predictable outputs)
        }
        
        int getRandom() {
    
            // modulus ki yahi to khaasiyat hoti h ki 0 se us number - 1 tak possibilities hoti h
    
            int r = rand() % size; // Generate a random index (0 to size-1)
            ListNode* temp = head;
    
            // Traverse the list to the r-th node
            for (int i = 0; i < r; i++) {
                temp = temp->next;
            }
    
            return temp->val; // Return the value at the random node
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(head);
     * int param_1 = obj->getRandom();
     */
    