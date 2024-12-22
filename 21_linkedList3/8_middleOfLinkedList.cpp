#include <bits/stdc++.h>
using namespace std;

/*Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node
*/

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


        for (int i=0; i<count/2; i++){
            temp = temp->next;
        }
        // 
        return temp;
        
    }
};




class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};


// single pass solution using slow and fast pointer...