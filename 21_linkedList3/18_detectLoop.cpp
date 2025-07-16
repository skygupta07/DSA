// slowFastPointer.cpp
// detectLoop.cpp

/*

You are given the head of a singly linked list. 
Your task is to determine if the linked list contains a loop. 
A loop exists in a linked list if the next pointer of the last node points to any other node 
in the list (including itself), rather than being null.


Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node 
to which the last node points to. If pos = 0, it means the last node points to null, 
indicating there is no loop.

Examples:

Input: head: 1 -> 3 -> 4, pos = 2
Output: true

Explanation: There exists a loop as last node is connected back to the second node.


Input: head: 1 -> 8 -> 3 -> 4, pos = 0
Output: false

Explanation: There exists no loop in given linked list.

Input: head: 1 -> 2 -> 3 -> 4, pos = 1
Output: true

Explanation: There exists a loop as last node is connected back to the first node.


Constraints:
1 ≤ number of nodes ≤ 1e4
1 ≤ node->data ≤ 1e3    

0 ≤ pos ≤ Number of nodes in Linked List

*/

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
}


bool detectLoop(Node* head) {

    if (head == NULL) return false;

    map <Node*, bool> visited;

    Node* temp = head;

    while(temp != NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}


class Solution {
public:

    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        
        if (head == NULL) return false; // If the list is empty, there's no loop.
        
        // abey saale race to dono ne hi bkl starting point se hi start kari thi...
        Node* slow = head;
        Node* fast = head;
        
        // Traverse the linked list with two pointers
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // Slow pointer moves one step
            fast = fast->next->next;     // Fast pointer moves two steps
            
            if (slow == fast) {          // If both meet, a loop is detected
                return true;
            }
        }
        
        return false; // If we exit the loop, there is no cycle.
    }
};
