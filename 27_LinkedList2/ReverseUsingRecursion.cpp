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

void display(Node* &head){
    if (head == NULL) return;  //base case
    // dekh tu chahe to temp variable bana ke value print kar sakta hai 
                    // ya phir directly head bhi use kar sakta hai...but head use kiya to 
                    // finally dislocate ho sakta hai...
    cout <<head->val<<" ";  // kaam 
    display(head->next);  // call
}
// although iterative soln is better but for printing reverse linked list(ll) 
// recursive soln is good only to write but there will be call stack of O(n)

void displayrev(Node* &head){
    if (head == NULL) return;  // base case
      // dekh tu chahe to temp pointer bana ke value print kar sakta hai 
                    // ya phir directly head bhi use kar sakta hai...

    displayrev(head->next); // call
    cout<<head->val<<" "; // kaam
}



int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    // Node is data type, a,b,c.. storing some address 
    
    // linking nodes
    a->next = b;  // &b nahi hoga since b itself is a address...
    b->next = c;
    c->next = d;
    d->next = e;

    // displayrec(a);
    cout<<endl;
    displayrev(a);
    cout<<endl;
    display(a);
// okay matlab endl aapka cout pe diya jaata hai....

}


