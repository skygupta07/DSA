#include <bits/stdc++.h>
using namespace std;

class Node{ // DLL ke node ki properties...
public:

    int data;
    Node* next;
    Node* prev;

    Node(int data){ //constructor
        this->data = data;
        this->next = NULL; // smart filling of nodes..
        this->prev = NULL;
    }
};
 
// actually creating (DLL class) ofcourse class node will help us..
// doubly linked list ki class banayi ek user defined data type banaya jiski ki properties usi 
// me define karunga
// jiska constructor usi me, jiske functions usi me...
class DLL{ 
public:

    Node* head;
    Node* tail;
    int size;

    // default constructor...
    DLL(){ // constructor me jo aapne properties define kar rakhi
    // un SABHI ki aap kuch default value set kar do..
        head = tail = NULL;
        size = 0;
    }
    
    void insertAtHead(int data){
        Node* temp = new Node(data);    // first work is to put that data into Node ka jhola..
        if (size == 0){
            head = tail = temp; // creating first node is like tu hi mata tu hi pita 
        }
        else{ // imagination only... (kadam kadam badhaye jaa khushi ke geet gaye jaa.. matlab pehle 
            // next ke liye kaam hoga then prev ke liye finally head ko next iteration ke liye ready bhi to karega...)

            temp->next = head;
            head->prev = temp; // extra as compared to singly LL
            head = temp;

        }
        size++;  // if ya else koi bhi condition hit ho size to increase hona hi hai..
    }
    
    void insertAtTail(int data){
        Node* temp = new Node(data);
        if (size == 0){
            head = tail = temp; // creating first node is like tu hi mata tu hi pita 
        }        
        else{   // important line flow...
            tail->next = temp;
            temp->prev = tail;  //extra
            tail = temp;    // then last mai tail ko temp pe leka aaye...
        }
        size++;
    }
    
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insertAtIdx(int idx, int val){
        if (idx<0 || idx>size){
            cout<<"invalid Index";
            return;
        }
        else if (idx==0){
            insertAtHead(val);
        }
        else if (idx==size){
            insertAtTail(val);
        }
        else{
            Node* t = new Node(val);
            Node* temp = head;

            for (int i=1; i<=idx-1; i++){ // ek kam position par pahucha
                temp = temp->next;
            }

            t->next = temp->next; // first step taken by the hanging node 
            // i.e. the first node.. taki relationship bani rahe
            temp->next = t;
            t->prev = temp; // extra to establish the previous connection
            t->next->prev = t; //extra
            size++;
        }

    }
    void deleteAtHead(){
        head = head->next;
        if (head!=NULL) head -> prev = NULL; 
        if (head == NULL) tail = NULL;  
        size--;
    }

    void deleteAtTail(){
        if (size == 0){
            cout<<"list is Empty: "<<endl;
            return;
        }
        else if (size == 1){
            deleteAtHead();
            return;
        }
        // upar wali cheez nahi chalti to ye neeche waala to karna hi hai...
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIdx(int idx){
        if (idx <0 || idx > size){
            cout<<"invalid index"<<endl;
            return;
        }
        else if (idx == 0){
            deleteAtHead();
        }
        else{
            Node* temp = head;
            for (int i=0; i<=idx-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next; // now temp->next has been changed to rhs so...
            temp->next->prev = temp;
            size--;
        }
    }
    
};




int main(){
    // class wagera bana to li now main fn me usko use kaise karu? start kaise karu?
    // step1: create object of that class..
    // now using the object call different object methods you declared above...

    DLL list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.display();
    list.insertAtTail(60);
    list.insertAtHead(70);
    list.display();
    list.deleteAtHead();
    list.display();
    cout<<list.size<<endl;

    list.insertAtHead(90);
}
