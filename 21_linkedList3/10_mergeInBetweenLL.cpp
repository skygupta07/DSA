#include <bits/stdc++.h>
using namespace std;

/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
The blue edges and nodes in the following figure indicate the result:
*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        
        ListNode* i = list1;
        ListNode* j = list1;
        ListNode* k = list2;

        while(a>1){
            i = i->next;
            a--;
        }

        while (b>=0){
            j = j->next;
            b--;
        }

        i->next = k;

        while (k->next != NULL){
            k = k->next;
        }
        k->next = j;

        return temp;
    }
};