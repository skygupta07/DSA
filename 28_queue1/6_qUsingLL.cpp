#include <iostream>
using namespace std;
class Node{ // LL Node class
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{    // Queue class
public:
    Node* head;     // data members 
    Node* tail;     // head tail or front, back
    int size;

    Queue(){    // constructor
        head=tail=NULL;
        size=0;
    }
    

    // member functions
    void enqueue(int data){ // all fn of queue should be in Queue class declared
        Node* temp = new Node(data);
        if (size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;    // phir tail ko temp pe le gaya 
        }
        size++;  // good habit
    }

    void dequeue(){
        if (size==0){
            cout<<"queue is Empty..";
            return;
        }

        else{   // imp
            Node* temp = head;
            head=head->next;
            size--;
            delete(temp);   // sach mai hi delete kar diya.. taki memory waste naa ho...
                            // wo peeche reh ke karta hi kya waise bhi...
        }
        
    }

    int front(){
        if (size==0){
            cout<<"queue is Empty..";
            return -1;
        }
        return head->data;        
    }

    int back(){
        if (size==0){
            cout<<"queue is Empty..";
            return -1;
        }
        return tail->data;        
    }

    int length(){
        return size;    // member fns all are brothers and sisters and now each other
                        // values if they go up and down....
    }

    bool isEmpty(){
        if (size==0) return true;
        else return false;
    }

    void display(){ // simple display fn hai..
        Node* temp = head;
        while (temp!=NULL){ // saare nodes/element print karwane ke liye...
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};



int main(){
    Queue q;  // sabse pehla kaam creation of object jisse hum khel sake..
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.display();
    cout<<q.length()<<endl;  
    
       
}


/*
LL important implementation...


-> advantage of linked list implementation of queue over array implementation...
1. LL unlimited size
2. easy implementation
3. no wastage of memory..


Disadvantage:
-> for each element we need to store both data and Node* next => double data is used..
*/