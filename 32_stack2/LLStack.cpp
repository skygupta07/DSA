#include<iostream>
using namespace std;

// create Node

class Node{  // convention is to write the class first letter as Capital..
public:   
    int data;
    Node* next;

    Node(int data){  // ha node ke constructor me to () fn sign aaega hi
        this->data = data;
        this->next = NULL;
    }
};

class Stack{  // user defined data type hote hai class...
public:
    Node* head;  // imp ,, stack me hai hi kya jo bhi hai head hi hai...
    int size;  // head naam ka pointer banaya uski self defined properties hongi 
                // like head->data    and    head->next

    Stack(){
        this->head = NULL; // bydefault aap kisi bhi pointer ko banaye to usey aap NULL se initialise kar de...
        this->size = 0;
    }
    // push, pop wale saare fn STACK wali Class ke andar hi likho..
    
    void push(int val){ //linked list se stack implement karte hue aapke naye nodes head pe insert hoge
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;  // imp to maintain the size for better code..
    }

    void pop(){
        if (head==NULL){
            cout<<"stack underflow.."<<endl;
            return;

        }
        else{
            head = head -> next;
            size--;
        }
    }
    int getTop(){
        if (head==NULL){
            cout<<"stack underflow."<<endl;
            return -1;
        }
        else{
            return head->data;
        }
        cout<<endl;
    }

    // void display(){
    //     Node* temp = head;
    //     while(temp!=NULL){
    //         cout<<temp->data<<" ";
    //         temp = temp->next;
    //     }
    //     cout<<endl;
    // }

 
    void print(Node* temp){  // using recursion
        if (temp == NULL) return; // return matlab chalo chalo ab wapas chalo jaha se aaye they...
        print (temp->next);
        cout<<temp->data<<" ";

    }

    void display(){
        Node* temp = head;
        print (temp);
        cout<<endl;
    }

 };

















int main(){
    Stack st;
    st.pop();  // will show underflow condition
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.push(5);
    cout<<st.getTop()<<endl;
    st.display();
}

// bottom to top is Normal order 
// top to bottom is reverse order