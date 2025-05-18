#include <bits/stdc++.h>
using namespace std;

class Node{ // DLL ka Node...
public:
    int data;
    Node* next;
    Node* prev;
    
    // constructor -> class ka name (parameter)
    Node(int data){
        this->data = data;
        this->next = NULL; // smart filling of Nodes..
        this->prev = NULL;
    }
};
// DLL ke Node ki class to define kar di now uske corresponding fns ko define karo yaha.

void display(Node* head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void displayRev(Node* tail){ //O(1) space //actual for dll
    while(tail!=NULL){  // === while (tail)
        cout<<tail->data<<" ";
        tail= tail->prev;
    }
    cout<<endl;
    
}

void displayRec(Node* head){ // O(n) space
    if (head == NULL) return;   // base case
    cout<<head->data;           // kaam
    displayRec(head->next);     // fn call
}

void displayRecRev(Node* head){ // O(n) space
    if (head == NULL) return;
    displayRecRev(head->next);
    cout<<head->data;   
}


int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    // 1 2 3 4 5 
    // establishing forward connection..
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    
    // establishing backward connection..
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    // by default a ka prev is null -> no need to write..
    display(a);
    displayRec(a);
    cout<<endl;
    displayRecRev(a);
    cout<<endl;
    displayRev(e);
}