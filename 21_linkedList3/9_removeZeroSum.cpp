#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes 
that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  
You may return any such answer.

 (Note that in the examples below, all sequences are serializations of ListNode objects.)

*/


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        unordered_map <int, ListNode*> mp;
        // key will be prefix sum , value is node upto which the prefix sum key is holding...
        mp[0] = dummyNode;
        int prefSum = 0;

        while (head != NULL){
            prefSum += head->val;

            if (mp.find(prefSum) != mp.end()){
                ListNode* start = mp[prefSum];
                int pf = prefSum;
                ListNode* temp = start;
                
                // for memory free
                while (temp->next != head){
                    temp = temp->next;
                    pf += temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
            }
            else{
                mp[prefSum] = head;
            }

            head = head->next;
        }

        ListNode* newHead = dummyNode->next;
        delete(dummyNode);
        return newHead;
    }
};


/*
whenever there is a chance that the head node will be deleted then it is better that you create the dummy node 
in advance...

O(nlogn) hum fenwick tree ya bst ya binary search mai laa pate hai...


-> maintaining prefix sum....
ps(j) - ps(i-1) = running sum (rs)
if rs == 0  =>  ps(j) = ps(i-1)

we can use hashmap to store info of previous sum val (ps)  ->   and the corresponding node...

mp of prefix sum,  also just before filling and updating the map value if same ps value occured earlier or not..
if yes, then remove it...

when you link the linked list connection directly from one node to another node...then node in between are also 
skipped...

unordered_map <int, listNode*> mp
    // previous sum, node


*/