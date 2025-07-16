// removeDuplicateFromSortedList.cpp

/*

Given the head of a sorted linked list, 
delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:

Input: head = [1,1,2]
Output: [1,2]


Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// interview
class Solution {
public:

    ListNode* deleteDuplicates(ListNode* head) {
        // zero or single node
        if (!head || !head->next) return head;

        // prev and curr pointer use

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){

            // if found duplicate
            if (prev->val == curr->val){
                ListNode* toDelete = curr;

                prev->next = curr->next;

                // pehle to curr hi move karega {kua paani rule}
                curr = curr->next;

                prev->next = curr;

                delete(toDelete);
            }

            // if found distinct move themselves one pointer ahead 
            else{

                prev = curr; // abey saale prev ko ta ab curr pe hi laega ...and then curr just uska next ho jaega...
                curr = curr->next;
            }
        }

        return head;
        
    }
};




#include <bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};


struct ListNode {

    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* &head) {
        // handling zero or single node case {here akash see that this condition will be checked once 
        // a very first time... coz there is no recursion ...
        // so none of the call will be called again....}
        
        if (head == NULL || head->next == NULL) return head;

        ListNode* a = head;
        ListNode* b = head->next;

        while(b != NULL){
            
            // skipping duplicates {ha bhai null wali condition always written first}
            while(b != NULL && (b->val == a->val)){
                b = b->next;
            }  

            // here at this point a and b will be distinct elements.. now insert links 

            a->next = b; // taki ll point kar sake sahi jagah..
            // updating a pointer - i.e. a points to the place where b is pointing...

            a = b;

            // next karne se pehle ye cheej check kar liya karo...
            if(b != NULL) b = b->next;
        }
        
        return head;
    }
};


