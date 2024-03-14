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