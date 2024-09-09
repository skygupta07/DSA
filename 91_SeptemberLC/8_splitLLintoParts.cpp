#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans; // ans vector of ListNode* will contain the pointer of first Node of
        // each part of Linked List
        int n = 0;
        ListNode* temp = head;
        while (temp!=NULL){
            temp = temp->next;
            n++;
        }
        // now n contains size of original LL and temp here pointing to null
        int size = n/k; // size of each part
        int rem = n%k;

        temp = head;

        while (temp!=NULL){
            ListNode* farji = new ListNode(100);    // farzi node..
            ListNode* farjiPtr = farji;    // farzi node to farzi node pointer

            int s = size;   // when you don't want to chedna the original...
            if (rem>0) s++;
            rem--;

            for (int i=1; i<=s; i++){
                farjiPtr->next = temp;
                temp = temp->next;  // temp waala next part ko aage jaake handle karega 
                farjiPtr = farjiPtr->next;
            }
            // ab tempC pointer banayi hui LL part ke end pe point kar rha hoga...
            // aur temp pointer just next wale part ke starting pe point kar rha hoga...
            farjiPtr->next = NULL; // IMP -> because yahi to batayega ki bc ye wali LL part khatam ho gayi hai..
            ans.push_back(farji->next); // c is the farzi node 
        }

        if (ans.size() < k){
            int extra = k - ans.size();
            for (int i=0; i<extra; i++){
                ans.push_back(NULL);
            }
        }
        return ans;   
    }
};


// n = 17, k= 5   4. 4. 3 3 3 
/*
size find as n
no. of parts = k
no. of elements in each part = n/k initially....
but if there are more elements left due to n%k then equally divide starting from the starting...




*/