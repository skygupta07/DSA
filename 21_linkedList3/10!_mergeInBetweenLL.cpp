// mergeInBetweenLinkedList.cpp

#include <bits/stdc++.h>
using namespace std;


/*

You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
The blue edges and nodes in the following figure indicate the result:
Build the result list and return its head.


Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]

Output: [10,1,13,1000000,1000001,1000002,5]

Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. 
The blue edges and nodes in the above figure indicate the result.


Example 2:


Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]

Explanation: The blue edges and nodes in the above figure indicate the result.
 

Constraints:

3 <= list1.length <= 1e4
1 <= a <= b < list1.length - 1
1 <= list2.length <= 1e4

*/

struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Pointers to find (a-1)th node and (b+1)th node
        ListNode* prevA = list1;  // i → list1[a-1]
        ListNode* afterB = list1; // j → list1[b+1]

        // Move prevA to (a-1)th node
        int count = 1;
        while (count < a) {
            prevA = prevA->next;
            count++;
        }

        // Move afterB to (b+1)th node
        count = 0;
        while (count <= b) {
            afterB = afterB->next;
            count++;
        }

        // Step 1: (a-1)th node ka next ab list2 ka head hona chahiye
        prevA->next = list2;

        // Step 2: list2 ke last node tak jao
        ListNode* tail2 = list2;
        while (tail2->next != NULL) {
            tail2 = tail2->next;
        }

        // Step 3: list2 ka last node ko b+1 position se jod do
        tail2->next = afterB;

        // Final merged list ka head wahi old list1 ka head hoga
        return list1;
    }
};
