#include <bits/stdc++.h>
using namespace std;

/*


Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 
Example 1:

Input

["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output

[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 10pow4
0 <= value <= 10pow5
At most 2 * 10pow5 calls will be made to get and put.

*/



class LRUCache {
public:

    class Node{ // doubly linked list ki node
    public: 
            int key;
            int val;

            Node* prev;
            Node* next;

            // constructor 
            Node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;    // capacity 
    unordered_map <int, Node*> mp;  // stores key and address of the node (from address we can simply fetch value)

    LRUCache(int capacity) {
        cap = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode){    // koi bhi nayi node add kar rahe ho to wo to most recently used hui kind of ... 
    // to simply usey head ke next pe lagao....
    // uskey liye jo existing head kisi ko point kar raha hoga... now pehle iss naye node ko 
    // ke links bethao...then head aur temp bhi baad mai bkl haath badhayenge...
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode){
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    
    int get(int key) {
        // agar wo map mai present h to wahi se uski value de dena ... but wait.. ab jaise hi 
        // element ko use kara now wo ab khud most recently used ho gaya 
        // so usko waha se hata ke head ke just next pe lagana padega...
        if (mp.find(key) != mp.end()){
            Node* resNode = mp[key];
            int ans = resNode -> val;

            mp.erase(key);  // purane wale ko hatao...
            deleteNode(resNode);
            addNode(resNode);

            // update mp with new address as well
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    // put karne se pehle ye dekho ki kya same key already present hai? 
    // agar ha to phir uss wali hi key ko erase karke then value update karo....
    // aur ha put karte waqt mp ka size ka constraint bhi dekho... 
    // agr bhar gaya h to tail ke pass wala deleteNode kar dena...

    // then finally add node and update its status on mp also....
    void put(int key, int value){
        
        if (mp.find(key) != mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        if (mp.size() == cap){
            mp.erase(tail -> prev -> key);  // erase karte huye key hi dena padta h..
            deleteNode(tail -> prev);
        }

        addNode(new Node(key, value));
        mp[key] = head->next;

    }
};



/*

suppose you have four tshirts -> you wear s1 on mon, 
s2 on tue, 
s3 on wed, 
s4 on thu => so here LRU shirt will be s1 (which was weared on mon)
*/



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 
 
 */