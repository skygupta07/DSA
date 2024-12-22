#include <bits/stdc++.h>
using namespace std;



 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 




class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if (c==NULL) return {-1,-1};    // jab do hi node hongi tab teesra to NULL hi touch kar dega..

        // for max distance
        if (c==NULL) return {-1,-1};
        while (c!=NULL){
            if (b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){
                if (fidx == -1) fidx = idx; // if not yet calculated then only put 
                else sidx = idx;    // else always update the second index...
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }

        if (sidx == -1) return {-1,-1};
        int maxd = sidx - fidx;  // max distance between two nodes..
        


        // now for calculating min. distance between critical points...
        int mind = INT_MAX;
        fidx = -1;      // instead of initiallising new variables I am simply reUsing older variables
        sidx = -1;
        idx = 1;    

        a = head;
        b = head->next;
        c = head->next->next;

        while (c){
            if (b->val > a-> val && b->val > c->val || b->val < a-> val && b->val < c->val){
                fidx = sidx;
                sidx = idx; // imp steps.. taaki min. distance hi nikale....
                if (fidx != -1){
                    int d = sidx - fidx;
                    mind = min(mind , d);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        return {mind, maxd};

        }



    
};

/*
agar first idx ek baar bhi find nahi hua to usko update karo...
else second idx ko hi update karte jao....















*/

