// mergeTwoSortedLinkedList.cpp

/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together 
the nodes of the first two lists.

Return the head of the merged linked list.


Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]


Example 2:

Input: list1 = [], list2 = []
Output: []


Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100

Both list1 and list2 are sorted in non-decreasing order.

*/

#include <bits/stdc++.h>
using namespace std;


class Node{
public:

    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
public:

    Node* sortedMerge(Node* head1, Node* head2) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        Node* dummy = new Node(-1);
        Node* temp3 = dummy;
        
        while (temp1 && temp2){

            if (temp1 -> data <= temp2 -> data){
                temp3 -> next = temp1;
                
                temp3 = temp3 -> next;
                temp1 = temp1 -> next;
            }

            else{
                temp3->next = temp2;
                
                temp3 = temp3 -> next;
                temp2 = temp2 -> next;
            }

        }
        
        if (temp1) temp3 -> next = temp1;
        if (temp2) temp3 -> next = temp2;
        
        return dummy -> next;
    }
};
