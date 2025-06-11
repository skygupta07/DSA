// deleteNodeInALinkedList.cpp

/*

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. 
You will not be given access to the first node of head.

All the values of the linked list are unique, 
and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. 
node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.


Example 1:


Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.


Example 2:


Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
 

Constraints:

The number of the nodes in the given list is in the range [2, 1000].
-1000 <= Node.val <= 1000
The value of each node in the list is unique.
The node to be deleted is in the list and is not a tail node.

*/



#include <bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    void deleteNode(ListNode* target) {
        target->val = target->next->val;
        target->next = target->next->next;
    }
};


class Solution {
public:
    void deleteNode(ListNode* node){
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;   
        delete temp; 
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Since we know input node is not last node, so nextNode will not be null
        ListNode *nextNode = node->next;
        // Step 2
        node->val = nextNode->val;
        // Step 3
        node->next = nextNode->next;
        nextNode->next = nullptr;   // agar point kar bhi raha hai to phar nahi padega agar ye line hata bhi di to
        delete(nextNode);
    }
};