#include <iostream>
using namespace std;

class Node{ // dekh node ko to public hi rakh magar jo main hai jiske liye aaye hai
// i.e. queue to uske members ko private aur public dekh liyo..
public:
    int data;
    Node* next;


    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }

};

class queue{
    Node* head;
    Node* tail;
    int size;

    public:
    // constructor
    queue(){  // initially jab ek bhi node nahi to apna head aur tail dono hi NULL ko point karenge...
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int data){
        // create node, 
        Node* newNode = new Node(data);
        if (this->head == NULL){
            this->head = this->tail = newNode;
        }
        else{
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
        
    }

    void dequeue(){
        if (this->head==NULL){ // linked list is empty...
            return;
        }

        else{
            Node* oldHead = this->head;
            Node* newHead = this->head->next;
            head = head->next;
            head = newHead;

            if (this->head==NULL) this->tail = NULL;
            oldHead->next = NULL;
            delete oldHead;

        }
        this->size--;
    }

    int getSize(){
        return this->size;
    }

    bool isEmpty(){
        if (this->head == NULL){
            cout<<"ll is empty..";
            return true;
        }
        else return false;
    }
    
    int getFront(){
        if (this->head == NULL){
            return -1;

        }
        else{
        return this->head->data;    
        }
    }


};












int main(){

    queue qu;
    qu.enqueue(2);
     qu.enqueue(5);
      qu.enqueue(6);
       qu.enqueue(8);
        qu.enqueue(12);
        
        qu.enqueue(23);

        while (not qu.isEmpty()){
            cout<<qu.getFront()<<" ";
        }















}