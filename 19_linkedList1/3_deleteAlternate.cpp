// given the head of a linked list, delete every alternate element from the list starting from the second element

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next; // next is a node pointer to the next node..

    // constructor
    Node(int data){
       this->data = data;
       this->next = NULL; // by default koi bhi node banao aap uski next pointer to null ko hi point karegi..
    }
};

void insertATHead(Node* head, int data){
    // in general linked list is passed through head pointer important---
    Node* new_node = new Node(data);
    new_node->next = head;// read as: new_node ke next ko head pe point karaya

    head = new_node; // then head ko new_node pe point karaya...
                    // since head should always point to the first node of linked list.. 
}

void insertAtTail(Node* &head, int data){

    // kisi bhi position pe insert karne ke liye node hona bhi to chahiye ,, isliye pehle to tum node banao..
    
    Node* new_node = new Node(data);
    Node* temp = head;  // Node* temp banaya jo ki(ek nodePOinTer hai) head ko point kar rha hoga...initially
    while (temp->next != NULL){ 
        temp = temp->next;

    }
    // do cheeze hoti hai ... while (temp != NULL) jab mujhe last node tak bhi cheeje process karwani hoti hai tab like size nikalne mai..
    // while (temp->next != NULL)   (bol bacchan car rule)   , second last node tak hi cheeje process hongi ..ha wo alag baat hai ki temp pointer to at the end last node pe point kar raha hoga...


    // now after the above while loop, nodePointer temp has reached the last node
    temp->next = new_node;
    // new_node->next = NULL;  // No need to write since our constructor is smartly designed

}

void insertAtPosition(Node* head, int data, int pos){
    // accha me chahta hu ki meri isi wali linked list me hi saare changes ho 
    // koi copy na bane isliye reference se bheja... arey bhai simply yaad 
    // rakh ki tujhe pointer hi bhejna padta hai....
    
    Node* new_node = new Node(data);
    Node* temp = head;
    int current_pos = 0;
    
    while (current_pos != pos -1){
        temp= temp->next;
        current_pos++;

        
    }
    // temp pointer is at pos-1
    new_node->next = temp->next;  // order is important else we can miss the access to our current node earlier...
    temp->next = new_node;

}

void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head){ // thoda sa indirectly hi hallal karke free karte hai...
    Node* temp = head;
    while(temp->next->next != NULL){ 
        temp= temp->next; 
    }
     // i.e. temp is at second last position
    Node* last = temp->next;    // save the last node
    temp->next = NULL;      // remove the last node
    free(last);         // free the memory of the last node
}   


void deleteAtPosition(Node* head, int pos){
    int curr_pos =   0;
    Node* prev = head;  // prev naam ka ek pointer banaya aur ussey waha point karaya 
                        // jaha phillal head point kar rha hai...
    while(curr_pos!= pos-1){
        curr_pos++;
        prev = prev->next;

    }
    // jab bhi while loop mai while (alpha != betaposition){
    // aur andar hum ek ek se increment kar rahe hote hai to sach mai hamara pointer ...
    // betaPosition par hi aake rukta hai....

    // prev is pointing to node at pos-1
    Node* temp = prev->next;  // i.e. node to be deleted
    prev->next = prev->next->next;
    free(temp);
}


void display(Node* &head) {  // again
    // temp node banao jo ki iss bar head ko point kar rha ho, while loop laga ke saare node print karwao..
    Node* temp = head;
    while (temp!=NULL){ // matlab jab tak aakhri tak na pahuch jaye
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

}



int main(){
    // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL;
    Node* head = NULL; // initial condition or base value..
    // or creation of an object of that class
    insertATHead(head, 3);
    display(head);
    insertATHead(head, 5);
    display(head);
    insertATHead(head, 9);
    display(head);

    insertAtTail(head, 10);
    display(head);
   
   insertAtPosition(head,83, 2);
   display(head);
   deleteAtHead(head);
   display(head);

   deleteAtTail(head);
   display(head);

   deleteAtPosition(head, 1);
   display(head);
}


// traversal in a singly linked list using head pointer
// head pointer is the pointer pointing to first node..
// basic functions implementation
// 1. display fn


















