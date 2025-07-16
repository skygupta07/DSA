// intersectionOfTwoLinkedLists.cpp


/*

Given the heads of two singly linked-lists headA and headB, 
return the node at which the two lists intersect. If the two linked lists have no intersection at all, 
return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. 
This is 0 if there is no intersected node.

listA - The first linked list.
listB - The second linked list.

skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

The judge will then create the linked structure based on these inputs and pass the two heads, 
headA and headB to your program. If you correctly return the intersected node, then your solution 
will be accepted.

Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.


Example 2:


Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.


Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

*/

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
        int m = 0;  // length of first Linked List
        int n = 0;  // length of second Linked List

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

        if (m > n){
            // LL A is big usi ke pointer ko aage laake barabari par laao..
            while (t--) headA = headA->next; 
        }
        
        else{
            while(t--) headB = headB->next;
        }


        while (headA != NULL && headB != NULL){
            if (headA == headB) return headA;

            // dono ka ek ek pointer aage badhao...
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


// brute force -> O(m+n), s.c. = O(1)

/*
The outer loop iterates over each node in the first linked list (headA).

For each node in headA, the inner loop iterates over each node in the second linked list (headB).
If any node in headA matches a node in headB, the method returns the intersection node.
If no intersection is found after all iterations, the method returns NULL

*/
class Solution {
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp;

        // first ll ke har node ke liye
        while (headA != NULL){

            // second ll ke saare element chalaye..
            temp = headB;
            
            while(temp != NULL){
                // kisi bhi moment pe equal mil gaye to maje h..
                if (headA == temp){
                    return headA;
                }

                // warna bhai apni search jaari rakho b ko aage badha ke...
                temp = temp->next;
            }

            // ha bhai apni search jaari rakho a ko aage badha kar...
            headA = headA->next;
        }

        // arey dono ll ke har element ko har element ke saath pair karke dekh liya ... ab tak nahi mil paya..
        // matlab kucch bhi common nahi h..
        return NULL;
    }
};








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
        
        // first linked list ke har element ki frequency store kar li..
        while (headA != NULL){
            mp[headA]++;

            headA = headA->next;
        }

        // now second linked list mai iterate karte waqt check karte h ki kya ye second list wala element 
        // kya already list1 mai present h?? agar ha to bhaiya return kardo ussi waqt ...
        while (headB != NULL){
            if (mp[headB] > 0) return headB;

            headB = headB->next;
        }

        // no intersection found
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