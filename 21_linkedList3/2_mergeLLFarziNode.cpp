// mergeLinkedListFarziNode.cpp

//LC 21

#include <bits/stdc++.h>
using namespace std;


class node { 
public:

    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node* &head, int data){
    node* new_node = new node(data);

    new_node->next = head;
    head = new_node;
}

void insertAtTail(node* &head, int data){
    // kisi bhi position pe element insert karne ke liye node hona bhi to chahiye ,, isliye pehle to tum node banao..
    
    node* new_node = new node(data);
    node* temp = head;  // Node* temp banaya jo ki head ko point kar rha hoga..filhaal
    
    while (temp->next != NULL){  // taki aakhri node pe aake ruk saku
        temp = temp->next;
    }

    // now after the while loop pointer temp has reached the last node
    temp->next = new_node;
    new_node->next = NULL;  // No need to write since our constructor is smartly designed
}

void displayLL(node* &head){
    node* temp = head;

    while (temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }

    cout<<"NULL"<<endl;
}

int lengthLL(node* &head){
    int n=0;

    node* temp = head;
    
    while(temp!=NULL){ // arey bhai jab puri length count karna chahta hai to puri LL traverse bhi to karega
        temp = temp->next; // but ha agar aisa kaam hai ki last wale node ki need hai tab to while(temp-next!=NULL) wali condition lagegi..
        n++;
    }

    return n;
}

node* mergeLL(node* h1, node* h2){
    node* h3 = new node(100); // initialise h3 with any random value..
    node* temp = h3;  // here temp is farzi node pointer
    
    while (h1 != NULL && h2 != NULL){

        if (h1->data <= h2->data){
            temp->next = h1;    // temp ke next ko h1 pe point karwa diya...
            h1 = h1->next;
            temp = temp->next;
        }
        
        else{
            temp->next = h2;
            h2 = h2->next;
            temp = temp->next;
        }

    }
    
    if (h1==NULL) temp->next = h2;  // h1 firstLinked List has exhausted..
    else temp->next = h1;
    
    return h3->next;  // farzi ke next node se hi actual LL chalu hogi...

}


int main(){
     // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL   #important
    node* h1 = NULL;

    //insertAtTail(h1,2); // pehla hi element daalne ke liye insertAtTail kiya to error throw kiya 
                            // due to null pointer exception..
   
    insertAtHead(h1,9);
    insertAtHead(h1,7);

    insertAtHead(h1,5);
    insertAtHead(h1,3);
    
    insertAtHead(h1,1);

    displayLL(h1);
    
    node* h2 = NULL;

    insertAtHead(h2,15);
    insertAtHead(h2,12);
    insertAtHead(h2,10);
    insertAtHead(h2,8);
    insertAtHead(h2,6);
    insertAtHead(h2,2);

    displayLL(h2);
    mergeLL(h1,h2);
    displayLL(h1); 
    return 0;
}