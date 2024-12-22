#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){ // constructor
        this->data = data;
        this->next = NULL;
    }
};

void display(Node* head){
    Node* temp = head;
    while (temp!= NULL){
        cout<<temp->data<<"->";
        temp= temp->next;  // imp, else infinite loop chal jaega
    }
    cout<<"NULL"<<endl;
}

void updateAtPosition(Node* head, int val, int pos){
    int curr_pos = 0;
    Node* temp = head;
    while(curr_pos != pos){
        temp= temp->next;
    }
    // temp is at position
    temp->data = val;
}

// we traverse on linked list nodes via help of temp pointer..






































int main(){
    Node* head = NULL;
    Node* new_node = new Node(4);
    display(new_node);
    updateAtPosition(new_node, 5,0);
    display(new_node);

}



