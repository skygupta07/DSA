#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int x){
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

void push(int x, Node* &top){
    Node* newNode = new Node(x);
    
    newNode->prev = top;
    top = newNode;
}

int pop(Node* &top){
    //if the stack is empty
    if(top == NULL){
        cout<<"Bhag ja yaha se"<<endl;
        return 0;
    }

    //otherwise
    int val = top->val;
    Node* temp = top;
    top = top->prev;
    delete(temp);

    return val;
}

int main(){
    Node* head = NULL;
    Node* top = head;

    push(1,top);
    push(2,top);
    push(3,top);
    push(4,top);
    push(5,top);

    cout<<pop(top)<<" ";  
    cout<<pop(top)<<" ";  
    cout<<pop(top)<<" ";  
    cout<<pop(top)<<" ";  
    cout<<pop(top)<<" ";  
    cout<<pop(top)<<" ";  
}