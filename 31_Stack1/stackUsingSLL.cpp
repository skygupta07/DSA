#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int x){
        this->val = x;
        this->next = NULL;
    }
};

void push(int x, node* &head, node* &top){
    //if pushing first element
    if(head == NULL){
        node* newNode = new node(x);
        head = newNode;
        top = head;
    }
    else{
        node* newNode = new node(x);
        top->next = newNode;
        top = newNode;
    }
}

int pop(node* &head, node* &top){
    //if deleting from empty list
    if(head == NULL){
        cout<<"Bhag ja yaha se"<<endl;
        return 0;
    }

    //if deleting from singleton list
    if(head == top){
        int val = top->val;
        node* temp = top;
        head = NULL;
        top = head;
        delete(temp);
        return val;
    }

    //otherwise
    node* temp = head;
    while(temp->next != top){
        temp = temp->next;
    }

    int val = top->val;
    top = temp;
    temp = temp->next;
    delete(temp);

    return val;
}

int main(){
    node* head = NULL;
    node* top = head;

    push(1, head, top);
    push(2, head, top);
    push(3, head, top);
    push(4, head, top);

    cout<<pop(head, top)<<" ";
    cout<<pop(head, top)<<" ";
    cout<<pop(head, top)<<" ";
    cout<<pop(head, top)<<" ";
    cout<<pop(head, top)<<" ";
}