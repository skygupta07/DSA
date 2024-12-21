#include <iostream>
using namespace std;

class Node{  // we are using class as user defined data type...
public:
    int data;
    Node* next;   // class ki help se bhi to hum ek data type hi define karte hai
                // isliye jaise int* pointername -> Node* pointername

    // constructor -> ha constructor mai jaruri thodi hai ki mai saare ke saare data members daalu..
    // but ha saare jo data members hai wo initialise to yahi honge...
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    // new node create
    Node* temp = new Node(d);   // created a Node with value d and name as temp
    temp->next = head;  // temp ka next will point to head...
    head = temp;    // head points to temp
}


void print(Node* &head){
    // reference se pass kiya taki copy na bane 
    Node* temp = head; // temp naam ka ek node pointer banaya jo ki head pe point kar rha ho..
    while (temp!=NULL){   // yani jab tak aakhri tak na pahuch jaye..
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1 = new Node(10);  // node ke andar element 10 hai..

    // cout<< node1->data <<endl;
    // cout<< node1->next <<endl;  
    Node* head = node1;
    

    print(head);

    insertAtHead(head,12);
    print(head);
    insertAtHead(head,15);
    print(head);

    insertAtHead(head,20);
    print(head);
    

}





