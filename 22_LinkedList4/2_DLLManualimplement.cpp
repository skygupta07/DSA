#include<iostream>
using namespace std;
class node{ // DLL ka node...
public:
    int data;
    node* next;
    node* prev;
    
    // constructor -> class ka name (parameter)
    node(int data){
        this->data = data;
        this->next = NULL; // smart filling of nodes..
        this->prev = NULL;
    }
};
// DLL ke node ki class to define kar di now uske corresponding fns ko define karo yaha.

void display(node* head){
    node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

void displayRev(node* tail){ //O(1) space //actual for dll
    while(tail!=NULL){  // === while (tail)
        cout<<tail->data<<" ";
        tail= tail->prev;
    }
    cout<<endl;
    
}

void displayRec(node* head){ // O(n) space
    if (head == NULL) return;   // base case
    cout<<head->data;           // kaam
    displayRec(head->next);     // fn call
}

void displayRecRev(node* head){ // O(n) space
    if (head == NULL) return;
    displayRecRev(head->next);
    cout<<head->data;   
}


int main(){
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d = new node(4);
    node* e = new node(5);

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