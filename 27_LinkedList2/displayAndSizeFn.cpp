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

void display(Node* head){
    Node* temp = head;
    // printing node values
    while (temp!= NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int size(Node* head){
    int count = 0;
    Node* temp = head;
    while (temp!= NULL){   // jaise hi temp null pe pahucha ab nahi chalega...
        count++;
        temp = temp->next;
    }

    return count;
}

int main(){
    Node* a = new Node(5);
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

    display(a); // since first node of linked list is the head node

    cout<<size(a)<<endl;
    

}
