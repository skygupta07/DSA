#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;  // tortoise and hare both at starting line
        ListNode* fast = head;  // slow and fast pointer...

        // constraint to faast par hi hai...wahi tej baagh raha hai...
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // har moment pe check kara ... increment karne ke baad ki agar wo 
            // same jagah point karne lage hai...=> there was loop somewher...
            if (slow == fast ) return true;
        } 
        return false;
    }
    
};

/*
while loop ke andar agar aapki pehli hi condition false ho gayi to wo andar ki next condition 
check nahi karta ...isliye yaha par hum bach jaenge...aur NULL->next nahi nikal rahe honge...


*/