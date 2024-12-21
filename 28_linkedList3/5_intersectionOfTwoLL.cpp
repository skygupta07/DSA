#include <bits/stdc++.h>
using namespace std;

struct ListNode {   // leetcode ki given class ki definition....
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0;
        int n = 0;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while (ptr1 != NULL){
            m++;
            ptr1 = ptr1->next;
        }

        while (ptr2 != NULL){
            n++;
            ptr2 = ptr2->next;
        }

        int t = abs(m-n);

        if (m>n){
            // LL A is big usi ke pointer ko aage laake barabari par laao..
            while (t--) headA = headA->next; 
        }
        else{
            while(t--) headB = headB->next;
        }

        while (headA != NULL && headB != NULL){
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};