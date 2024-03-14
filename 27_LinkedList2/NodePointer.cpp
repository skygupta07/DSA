#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int v){ // constructor
        this->val = v;
        this->next = NULL; // by default jitne bhi nodes banenge unke next wale section me NULL pointer lag jaega..
    }

};

int main(){
    Node* a = new Node(5);  // creation of new nodes...
    Node* b = new Node(10);
    Node* c = new Node(15);
    Node* d = new Node(20);
    Node* e = new Node(25);

    // Node is data type, a,b,c.. storing some address 
    
    // linking nodes
    a->next = b;  // &b nahi hoga since b itself is a address...
    b->next = c;
    c->next = d;
    d->next = e;

    Node* temp = a;
    // printing node values
    while (temp!= NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }



}

// stick to basics: pointers kya karte hai,, arrey wo to address store karte hai 
// accha matlab node ka pointer bhi address store karega now iss baar node ka address ka store karega...


// NULL is a simple type of address...
// agar hum array me recursion laga sakte hai to linked list me kyu nahi...
// NULL ek special type of node hai jo kucch bhi store nahi karta...NULL ka koi val nahi hota,, aur NULL ka koi next nahi hota...