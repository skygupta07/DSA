#include<iostream>
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
 
class Deque{ // actually creating (DLL class) ofcourse class Node will help us..
// doubly linked list ki class banayi ek user defined data type banaya jiski ki properties usi 
// me define karunga
// jiska constructor usi me, jiske functions usi me...
public:
    Node* head;
    Node* tail;
    int s;  // size

    // default constructor...
    Deque(){ // constructor me jo aapne upar data members define kar rakhi
    // hai.. un SABHI ko aap kuch default value set kar do..
        head = tail= NULL;
        s = 0;
    }
    
    void pushFront(int data){   // salman bhai car se aate huye...
        Node* temp = new Node(data);    // first work is to put that data into Node ka jhola..
        if (s == 0){
            head = tail = temp; // creating first node is like tu hi mata tu hi pita 
        }
        else{ // imagination only...
        // yaha temp pehle propose karega ... since always move forward in life...
            temp->next = head; // temp ka next will point to head...
            head->prev = temp; // extra as compared to singly LL 
                                // (head ka previous will point to temp)
            head = temp;    // head will point to temp
        }
        s++;  // if ya else koi bhi condition hit ho size to increase hona hi hai..
    }
    
    void PushBack(int data){
        Node* temp = new Node(data);
        if (s == 0){
            head = tail = temp; // creating first node is like tu hi mata tu hi pita 
        }        
        else{   // important line flow... (always move forward in life...
            // yaha par tail pehle propose karega....)
            tail->next = temp;
            temp->prev = tail;  //extra
            tail = temp;    // then last mai tail ko temp pe leka aaye...
        }
        s++;
    }
    
    void display(){
        Node* temp = head;
        while(temp!=NULL){  // ya phir size bhi calcualte kar rha hota tab bhi yahi..
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    
    
    void popFront(){
        head = head->next;
        if (head!=NULL) head -> prev = NULL; // more than one element honge..
        if (head == NULL) tail = NULL;      // ek hi element tha wo bhi chala gya to..
        s--;
    }

    void popBack(){
        if (s == 0){
            cout<<"list is Empty: "<<endl;
            return;
        }
        else if (s == 1){
            popFront();
            return;
        }
        // upar wali cheez nahi chalti to ye neeche waala to karna hi hai...
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        s--;
    }

    int length(){
        return s;    // member fns all are brothers and sisters and know each other
                        // values if they go up and down....
    }

    bool isEmpty(){
        if (s==0) return true;
        else return false;
    }

    
};

int main(){
    Deque dq;
    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushBack(3);
    dq.PushBack(4);
    dq.PushBack(5);
    dq.display();

    dq.popBack();
    dq.popFront();
    dq.display();
    dq.PushBack(6);
    
}













/*

here both operation are allowed at front and back...i.e. both push and pop operation..
-> you can use doubly Linked list
so that push_back () , pop back all takes O(1) time







*/