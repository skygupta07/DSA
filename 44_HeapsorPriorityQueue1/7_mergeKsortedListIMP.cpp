// pehle to priority queue mai int wagera use hota tha but yaha aap linked list ke head nodes wagera daaloge 
// priority queue mai isliye yaha use karo custom comparator....

#include <bits/stdc++.h>
using namespace std;


/*

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/


//  Definition for singly-linked list.
struct ListNode{

      int val;
      ListNode *next;

      // constructor
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class cmp{  // custom comparator -> ratto
public: 
    bool operator()(const ListNode* l1, const ListNode* l2){    // batana padata hai at a time kya do vastu aaengi..
        return l1->val > l2->val;       //  decreasing order mai chahte hai sort karna...to wahi return kar do...
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {   // saari linked list ke head diye honge...
        // min heap priority queue
        
        priority_queue <ListNode* , vector<ListNode*> , cmp > pq;  // syntax
        
        for (int i=0; i<lists.size(); i++){
            if (lists[i]==0) continue;
            pq.push(lists[i]);
        }


        ListNode* dummy = new ListNode(-1); // creation of LinkeList Node
        ListNode* ptr = dummy;     // creation of pointer and pointing it to the dummy node..
        
        
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            if (curr->next != NULL) pq.push(curr->next);
            ptr->next = curr;
            ptr = ptr->next;
        }

        return dummy->next;
    }
};



/*

// best min. first candidates are the first element of list
// priority queue ka use kiya, inbuilt min heap use karne ke liye 
wo greater wale ke liye cmp class banayi....(asked in google)

// priority queue mai element ListNode* wale honge
// vector (with name lists) me iterate karke har element ko priorityqueue me push kiya
// ek dummy node aur uske liye ek pointer create kiya
final answer dummy ka next hoga..

dekho agar simple merge sort hota tab to do array pe do pointer easily compare bhi ho jaate 
and result mai daal dete they but yaha nahi chalega ....

try karo inhi linked list ko aapas mai manipulate karke likho...

-> ek saath linked list ke heads ko dekho....minheap ke kaaran jis bhi linked list se sabse min. wala 
element aaega ussey fetch karo and uske next wale element ko then min heap mai daal do...

*/