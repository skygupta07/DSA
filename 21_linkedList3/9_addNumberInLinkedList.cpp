// addNumberInLinkedList.cpp

/*

Given the head of two singly linked lists num1 and num2 representing two non-negative integers. 
The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by 
the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros 
in the output list.


Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.

Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 

Explanation: Given numbers are 63 and 7. There sum is 70.


Constraints:
1 <= size of both linked lists <= 1e6
0 <= elements of both linked lists <= 9

*/

#include <bits/stdc++.h>
using namespace std;

// Structure of the Node in the linked list
struct Node {
    int data;       // Holds the digit
    struct Node* next;

    Node(int x) {   // Constructor to initialize node with a digit
        data = x;
        next = NULL;
    }
};

class Solution {
public:
  
    // Utility function to reverse a linked list
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        
        // Iteratively reverse the pointers
        while (curr){
            Node* next = curr -> next; // store next node
            curr -> next = prev;       // reverse the link

            prev = curr;               // move prev ahead
            curr = next;               // move curr ahead
        }
        
        return prev; // new head of reversed list
    }

    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* l1, Node* l2) {
        // Step 1: Reverse both lists to simplify addition (units digit comes first)
        l1 = reverse(l1);  // e.g., 2->4->3 becomes 3->4->2
        l2 = reverse(l2);  // e.g., 5->6->4 becomes 4->6->5
        
        Node* dummy = new Node(-1); // dummy node to simplify handling of head
        Node* ptr = dummy;          // pointer to build the result list
        
        int carry = 0; // to handle carry from sum of digits
        
        // Step 2: Traverse both reversed lists and perform digit-wise addition
        while (l1 || l2 || carry){
            int sum = carry; // initialize sum with any carry from previous addition
            
            if (l1){
                sum += l1 -> data; // add digit from l1
                l1 = l1 -> next;   // move to next node
            }
            if (l2){
                sum += l2 -> data; // add digit from l2
                l2 = l2 -> next;   // move to next node
            }
            
            carry = sum / 10; // calculate new carry (e.g., 14/10 = 1)
            
            ptr -> next = new Node(sum % 10); // create node with current digit (e.g., 14 % 10 = 4)
            ptr = ptr -> next;                // move ptr ahead to build result
        }
        
        // Step 3: Reverse the result to restore correct order (as we added from LSB to MSB)
        Node* res = reverse(dummy -> next);
        
        delete dummy;   // free dummy node's memory
        
        // Step 4: Remove leading zeros (if any) except when result is 0
        while (res && res -> next && res -> data == 0 ){
            Node* temp = res;
            res = res -> next;
            delete temp; // remove node with 0 at front
        }
        
        return res; // final result linked list
    }
};
