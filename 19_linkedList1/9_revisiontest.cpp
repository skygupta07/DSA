#include <bits/stdc++.h>
using namespace std;

class ListNode{ // user defined data type
public:
    int data;
    ListNode* next;

    // constructor
    ListNode(int val){
       this->data = val;
       this->next = NULL; 
    }
};

void display(ListNode* head){
    ListNode* temp = head;

    while (temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<"\n";
}

void insertAtHead(ListNode* &head, int val){
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode* &head, int val){
    ListNode* temp = head;  // temp Node* variable to be used as iterator over the linkedlist
    
    while (temp->next != NULL){
        temp = temp->next;
    }

    ListNode* newNode = new ListNode(val);
    temp->next = newNode;
}

void insertAtPosition(ListNode* &head, int pos, int val){
    ListNode* temp = head;
    
    while (pos-- > 1){
        temp = temp->next;
    }

    ListNode* newNode = new ListNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteAtHead(ListNode* &head){
    ListNode* tempNode = head;
    head = head->next;
    free(tempNode);
}

void deleteAtTail(ListNode* &head){
    // reach till second last
    ListNode* temp = head;
    while (temp->next->next != NULL){
        temp = temp->next;
    }

    ListNode* tempNode = temp->next;
    temp->next = NULL;
    
    free(tempNode);
}

void deleteAtPosition(ListNode* &head, int pos){    // assumed position as index
    ListNode* temp = head;

    while(pos-- > 1) {  // reached to pos-1 node
        temp = temp->next;
    }

    ListNode* tempNode = temp->next;
    temp->next = temp->next->next;
    free(tempNode);
}

int main(){

    // 10-> 5 -> 3 -> 2 -> 1
    ListNode* head = new ListNode(1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 5);
    insertAtHead(head, 10);

    deleteAtPosition(head,3);

    deleteAtHead(head);
    display(head);
}