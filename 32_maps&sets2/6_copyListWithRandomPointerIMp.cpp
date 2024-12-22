#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create a mapping of original nodes to their corresponding new nodes
        unordered_map<Node*, Node*> mp;
        Node* temp = head;  // pointer to iterate over linked list

        // Create all new nodes and store them in the map
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Set the next and random pointers for the new nodes
        temp = head;
        while (temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        // Step 3: Return the head of the new list
        return mp[head];
    }
};
