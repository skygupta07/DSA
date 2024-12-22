#include<iostream>
using namespace std;

class node{
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
    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    node* new_node = new node(data);
    temp->next = new_node;
}

void printNodes(node* &head){
    node* temp = head;  // LHS ko ye kar diya ya bole to RHS ki value LHS me daal di
    while (temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

void deleteDuplicates(node* &head){
    node* a = head;
    node* b = head->next;
    while(b!=NULL){
        while(b!=NULL && b->data==a->data){  // actually we are trying to avoid null pointer exception
         // as much as possible....and it becomes the constraint of condition also...
            b=b->next;
        }
        a->next = b;
        // now for next group of people
        a=b;
        if (b!=NULL){
            b=b->next;
        }

    }
}

int main(){
     // start with empty linked list i.e. there will be no node and 
    // head pointer pointing to NULL   #important
    node* root = NULL;
    insertAtHead(root,40);
    insertAtHead(root,40);
    insertAtHead(root,30);
    insertAtHead(root,20);
    insertAtHead(root,20);
    insertAtHead(root,10);
    insertAtHead(root,10);
    insertAtHead(root,10);
    printNodes(root);
    deleteDuplicates(root);
    printNodes(root);

    return 0;
}

