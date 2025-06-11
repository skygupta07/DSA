#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next; // next is a node pointer to the next node..

    // constructor
    Node(int data){
       this->data = data;
       this->next = NULL; // by default koi bhi node banao aap uski next pointer to initially null ko hi point karegi..
    }
};

void insertAtHead(Node* &head, int data){
    // in general linked list is passed through head pointer important---
    Node* new_node = new Node(data);
    new_node->next = head;// read as: new_node ke next ko head pe point karaya

    head = new_node; // then head ko new_node pe point karaya...
                    // since head should always point to the first node of linked list.. 
}

void insertAtTail(Node* &head, int data){
    // kisi bhi position pe element insert karne ke liye node hona bhi to chahiye ,, isliye pehle to tum node banao..
    Node* new_node = new Node(data);
    
    Node* temp = head;  // Node* temp banaya jo ki head ko point kar rha hoga..filhaal
    while (temp->next != NULL){  // taki aakhri node pe aake ruk saku {bol bacchan}
        temp = temp->next;
    }
    // now after the while loop pointer temp has reached the last node
    temp->next = new_node;
    // new_node->next = NULL;  // No need to write since our constructor is smartly designed
}

void insertAtPosition(Node* &head, int data, int pos){
    // accha me chahta hu ki meri isi wali linked list me hi saare changes ho 
    // koi copy na bane isliye reference se bheja...#pointers bheja..
    Node* new_node = new Node(data);
    Node* temp = head;
    int current_pos = 0;
    
    while (current_pos != pos -1){
        temp= temp->next;
        current_pos++;  
    }
    
    // temp pointer is at pos-1

    // you have to do no one else will do it for you... 
    // yaha bhi apply ho rha h.. ab iss new_node ko insert hona tha...to dekh pehle 
    // isko haath isi ko badhana pada {kua paani Rule}, haa baad mai apna kaam nikalwane ke liye phir usne 
    // bhi link jod diya aakhri mai....

    new_node->next = temp->next;  // order is important else we can miss the access to our current node earlier...
    temp->next = new_node;

}

void display(Node* &head){  // again
    // temp node banao jo ki iss bar head ko point kar rha ho, while loop laga ke saare node print karwao..
    Node* temp = head;
    while (temp!=NULL){  // saari nodes print karana /  ya puri ll ka size nikalne ke liye aakhri tak jaana bhi to padega..
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl; // since bydefault last node points to NUll pointer...
}


int main(){
    // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL   #important
    Node* head = NULL;
    insertAtHead(head, 3);
    display(head);
    insertAtHead(head, 5);
    display(head);
    insertAtHead(head, 9);
    display(head);

    insertAtTail(head, 10);
    display(head);
   
   insertAtPosition(head,83, 2);
   display(head);
}

// traversal in a singly linked list using head pointer
// head pointer is the pointer pointing to first node..
// basic functions implementation
// 1. display fn


















