#include <bits/stdc++.h>
using namespace std;

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p = NULL;
        ListNode* q = slow;
        ListNode* r = slow->next;

        while (q!=NULL){
            r = q->next;
            q->next = p;

            p = q;
            q = r;
        }

        ListNode* head1 = head;
        ListNode* head2 = p;

        // stopping condition from diagram...

        while (head2->next != NULL){
            ListNode* temp = head1->next;
            head1->next = head2;
            head1 = temp;

            temp = head2->next;
            head2->next = head1;
            head2 = temp;
        }
    }
};