// removeZeroSumConsecutiveNodesFromLinkedList.cpp

#include <bits/stdc++.h>
using namespace std;


/*

Given the head of a linked list, we repeatedly delete consecutive sequences of nodes 
that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  
You may return any such answer. 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.


Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.

*/


struct ListNode{
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    ListNode* removeZeroSumSublists(ListNode* head) {
        // Dummy node banaya jise head ke pehle attach kiya — helpful for edge cases
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        // Prefix sum map: key = prefix sum, value = node jahan tak wo prefix sum aaya tha
        unordered_map <int, ListNode*> mp;

        // 0 prefix sum dummyNode tak aaya hai — initialize kar diya
        mp[0] = dummyNode;
        int prefixSum = 0;

        // List ko traverse karte hain
        while (head != NULL) {
            prefixSum += head->val;

            // Agar ye prefixSum pehle aa chuka hai
            if (mp.find(prefixSum) != mp.end()) {

                // Mtlb beech ke nodes ka sum zero hai — remove them
                ListNode* start = mp[prefixSum];  // Ye wo node hai jahan se zero sum start hua
                ListNode* temp = start;

                int sum = prefixSum;

                // Clean up: Map se beech ke sab prefix sums hata do (memory clear + map consistency)
                while (temp->next != head) {
                    temp = temp->next;
                    sum += temp->val;

                    mp.erase(sum);
                }

                // Skip zero sum sublist by linking start directly to head->next
                start->next = head->next;
            } 
            
            else {
                // Naya prefix sum, map me store kar lo
                mp[prefixSum] = head;
            }

            // Move forward
            head = head->next;
        }

        // Final updated list head
        ListNode* newHead = dummyNode->next;

        delete dummyNode; // Memory cleanup

        return newHead;
    }
};



/*
whenever there is a chance that the head node will be deleted then it is 
better that you create the dummy node 
in advance...

O(nlogn) hum fenwick tree ya bst ya binary search mai laa pate hai...


-> maintaining prefix sum....
ps(j) - ps(i-1) = running sum (rs)
if rs == 0  =>  ps(j) = ps(i-1)

we can use hashmap to store info of previous sum val (ps)  ->   and the corresponding node...

mp of prefix sum,  also just before filling and updating the map value if same ps value occured earlier 
or not..
if yes, then remove it...

when you link the linked list connection directly from one node to another node...
then node in between are also 
skipped...

unordered_map <int, listNode*> mp
    // previous sum, node

*/