#include <iostream>
using namespace std;
class node{ // LL node class
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Queue{    // Queue class
public:
    node* head;     // data members 

    node* tail;     // head tail or front, back
    int size;
    Queue(){    // constructor
        head=tail=NULL;
        size=0;
    }
    

    // member functions
    void enqueue(int data){ // all fn of queue should be in Queue class declared
        node* temp = new node(data);
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
            node* temp = head;
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
        node* temp = head;
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



-> for each element we need to store both data and node* next => double data is used..
*/