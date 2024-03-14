#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next= NULL;
    }
};

// Node class, insert at head, tail, at any position..(fn definition written outside the class)
// display fn..


void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);  // us data ko daal ke ek node banayi
    temp->next = head;
    head = temp;                                // then us node ka naata inke saath joda..
}

void insertAtTail(Node* &head, int data){
    Node* temp = new Node(data);
    Node* t = head;
    while (t->next != NULL){
        t = t->next;
    }
    t->next = temp;
}

void display(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}





int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->next =b;
    b->next =c;
    c->next =d;
    d->next =e;
    e->next =f;

    
    insertAtTail(a,24);
    display(a);



}