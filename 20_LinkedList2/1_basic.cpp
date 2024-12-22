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
    Node a(12);
    Node b(15);
    Node c(17);
    Node d(24);
    Node e(28);

    cout<<a.val<<endl;
    cout<<a.next<<endl;

    // now start linking nodes with each other
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    cout<<a.next->next->next->val<<endl;

    // printing value using while loop
    Node temp = a;

    while(1){
        cout<<temp.val<<" ";
        
        if (temp.next == NULL){
            break;
        }
        temp = *temp.next;
    }

    



}


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
// accha matlab node ka pointer bhi address store karega now iss baar node ka address ko store karega...


// NULL is a simple type of address...
// agar hum array me recursion laga sakte hai to linked list me kyu nahi...
// NULL ek special type of NODE hi hai jo kucch bhi balue store nahi karta...NULL ka koi val nahi hota,, aur NULL ka koi next nahi hota...`