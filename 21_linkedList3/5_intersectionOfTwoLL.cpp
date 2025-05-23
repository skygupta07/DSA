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




// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;

        while (headA!=NULL){
            temp = headB;
            while(temp!=NULL){
                if (headA == temp){
                    return headA;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return NULL;
    }
};

// brute force -> O(m+n), s.c. = O(1)

/*
The outer loop iterates over each node in the first linked list (headA).
For each node in headA, the inner loop iterates over each node in the second linked list (headB).
If any node in headA matches a node in headB, the method returns the intersection node.
If no intersection is found after all iterations, the method returns NULL

*/






// ------- HASHMAP solution -------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode* ,int> mp;

        while (headA != NULL){
            mp[headA]++;

            headA = headA->next;
        }

        while (headB != NULL){
            if (mp[headB] > 0) return headB;
            headB = headB->next;
        }

        return NULL;
    }
};


/*

The first while loop iterates through all nodes in headA, storing each node in an unordered_map with a count.
The second while loop iterates through all nodes in headB, checking if each node exists in the map.
If a node from headB is found in the map, it means this node is the intersection node, and it is returned.
If no intersection node is found, the method returns NULL

*/



// ------length difference solution --------


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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