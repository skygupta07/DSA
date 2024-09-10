#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != NULL){
            int a = prev->val;
            int b = curr->val;
            int hcf = __gcd(a, b);

            ListNode* temp = new ListNode(hcf);
            
            temp -> next = curr;
            prev -> next = temp;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};