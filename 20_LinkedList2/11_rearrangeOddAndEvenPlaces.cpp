// oddEvenLinkedList.cpp

/*

Given the head of a singly linked list, group all the nodes with odd indices together 
followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]


Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 10pow4].
-10pow6 <= Node.val <= 10pow6

*/


#include <bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(int data){ 
        this->data = data;
        next = NULL;
    }
};


//  Definition for singly-linked list.

  struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

Node* oddEvenList(Node* head) {
    if (!head || !head->next) return head; // If list is empty or has only one node, return as is.

    Node* odd = head; // Pointer to the first odd-indexed node.
    Node* even = head->next; // Pointer to the first even-indexed node.
    Node* evenHead = even; // Save the head of even-indexed nodes. {ye sab choti moti chalaki hi h... bas}

    while (even && even->next) {
        odd->next = even->next; // Link current odd node to the next odd node.
        odd = odd->next; // Move odd pointer to the next odd node.
        
        even->next = odd->next; // Link current even node to the next even node.
        even = even->next; // Move even pointer to the next even node.
    }

    odd->next = evenHead; // Attach the even-indexed list after the odd-indexed list.
    return head;
}




class Solution {
    public:
        ListNode* oddEvenList(ListNode* head){
            vector <int> v;
            ListNode* temp = head;
    
            while(temp){
                v.push_back(temp->val);
                temp = temp->next;
            }
    
            int n = v.size();
    
            temp = head;
    
            for (int i=0; i<n; i+=2){
                temp->val = v[i];
                
                temp = temp->next;
            }

            // jump by two steps...
            for (int i=1; i<n; i+=2){
                temp->val = v[i];
    
                temp= temp->next;
            }
    
            return head;
            
        }
    };
    
    // good is to rearrange the data...start at odd index ...jump by two step...



class Solution {
    public:
        // ListNode* oddEvenList(ListNode* head) {
            // zero or one or two length LinkedList ke liye kucch karne ki need nahi..
            if (!head || !head->next || !head->next->next) return head;
    
            ListNode* odd = head;
            ListNode* even = head->next;
    
            ListNode* even_start = head->next;
    
            while (odd->next && even->next){
                odd->next = even->next; // connect all odds
                even->next = odd->next->next;   // connect all evens

                odd = odd->next;
                even = even->next;
            }

            odd->next = even_start; // place the first even node after the last odd node..
            return head;

          }
    };