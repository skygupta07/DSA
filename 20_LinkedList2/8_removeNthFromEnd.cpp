#include <bits/stdc++.h>
using namespace std;


/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=new ListNode();
        temp->next=head;

        ListNode* fast=temp;
        ListNode* slow=temp;

        for(int i=1;i<=n;i++){
             fast=fast->next;
        }

        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* gaya=slow->next;
        slow->next=slow->next->next;
        delete(gaya);
        
        return temp->next;
    }
};

// maintain two pointers and update one with a delay of n steps....