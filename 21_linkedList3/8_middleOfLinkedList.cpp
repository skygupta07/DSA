// middleOfLinkedList.cpp

/*

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

*/


#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* middleNode(ListNode* head){
        ListNode* temp = head;
        int count = 0;

        while (temp!=NULL){
            count++;
            temp = temp->next;
        }

        temp = head;
        // yes both case are being handled here...

        for (int i=0; i<count/2; i++){  
            temp = temp->next;
        }
        
        return temp;    
    }
};




class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // slow fast dono pointer initially head pe..
        ListNode* slow = head;
        ListNode* fast = head;

        // mujhe pata h ki fast ko do kadam chalwana h to uske pehle kadam ko secure kara then second kadam
        // ko secure kara...

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        // middle to slow pe hi hoga...
        return slow;
    }
};


// single pass solution using slow and fast pointer...