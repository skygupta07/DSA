// mergeTwoSortedLinkedList.cpp

//ll21

#include <bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head, int data){
    Node* new_Node = new Node(data);

    new_Node->next = head;
    head = new_Node;
}

void insertAtTail(Node* &head, int data){

    // kisi bhi position pe element insert karne ke liye Node hona bhi to chahiye, 
    // isliye pehle to tum Node banao..
    
    Node* new_Node = new Node(data);

    Node* temp = head;  // Node* temp banaya jo ki head ko point kar rha hoga..filhaal
    while (temp->next != NULL){  // taki aakhri Node pe aake ruk saku
        temp = temp->next;
    }

    // now after the while loop pointer temp has reached the last Node
    temp->next = new_Node;
    new_Node->next = NULL;  // No need to write since our constructor is smartly designed

}

void displayLL(Node* &head){
    Node* temp = head;

    while (temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
}

int lengthLL(Node* &head){
    int n = 0;
    Node* temp = head;

    while(temp!=NULL){ // arey bhai jab puri length count karna chahta hai to puri LL traverse bhi to karega
        temp = temp->next; // but ha agar aisa kaam hai ki last wale Node ki need hai tab to while(temp-next!=NULL) wali condition lagegi..
        n++;
    }

    return n;
}

void mergeLL(Node* h1, Node* h2, Node* h3){
    Node* tempA = h1;
    Node* tempB = h2;
    Node* tempC = h3;
      
    while(h1!=NULL && h2!=NULL){

        if (tempA->data <= tempB->data){
            Node* t = new Node(tempA->data);
            tempC->next= t;

            tempC = t;
            tempA = tempA->next;    
        }

        else{ // B<A -> B jeet gaya
            Node* t = new Node(tempB->data);
            tempC->next = t;
            tempC = t;
            tempB = tempB->next; // b jeeta to bhaiya b ka hi to pointer aage karoge...
        }

        // try kario ek baar while loop se bahar likh ke try kar..
        if (tempA == NULL) tempC->next = tempB;

        else tempC->next = tempA;
    } 
}



int main(){
     // start with empty linked list i.e. there will be no Node and 
    // head pointer pointing to NULL   #important
    Node* h1 = NULL;

    //insertAtTail(h1,2); // pehla hi element daalne ke liye insertAtTail kiya to error throw kiya 
                            // due to null pointer exception..
   
    insertAtHead(h1,9);
    insertAtHead(h1,7);
    insertAtHead(h1,5);
    insertAtHead(h1,3);
    insertAtHead(h1,1);

    displayLL(h1);
    
    Node* h2 = NULL;

    insertAtHead(h2,15);
    insertAtHead(h2,12);
    insertAtHead(h2,10);
    insertAtHead(h2,8);
    insertAtHead(h2,6);
    insertAtHead(h2,2);

    displayLL(h2);
    Node* h3 = new Node(100); // farzi Node..
    mergeLL(h1,h2,h3);
    
    return 0;
}