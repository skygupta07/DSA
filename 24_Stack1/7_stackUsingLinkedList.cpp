#include <iostream>
using namespace std;

class Node{   // linked list ke node ke liye class banai..
public:
    int data;
    Node* next;

    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class stack{ 

    Node* head;     // head is a pointer to trace elements
    int capacity;
    int curr_size;

public: // accha public ki shuruat constructor se hi hoti hai...(waise ekdum upar se bhi kar sakta hai....)

    // constructor
    stack(int c){
        this->capacity = c;
        this->head = NULL;
        this->curr_size = 0;
    }
    // push, pop, isEmpty , isFull, getTop

    void push(int data){
        Node* new_node = new Node(data);
        new_node->next = head;  //new_node ke next ko head par point karwaya..
        head = new_node;    // then head ko newnode pe point karwaya
        curr_size++;
    }

    void getTop(){
        if (head==NULL) cout<<"underflow";
        else cout<<this->head;
    }

    void pop(){
        Node* temp = head;  // ek temp naam ka node pointer banaya jo ki current head pe point
                                // kar rha ho.
        head = head->next;  // simply head ko aage node pe point karwa diya
        free(temp);

        curr_size--;
    }

};




int main(){
    stack st(6); // stack of size 6
    st.push(1);
    st.push(4);
    st.push(7);
    st.pop();
    st.push(41);
    st.push(9);
    st.pop();
    st.push(72);
    st.getTop();
    
}


// gfg stack using array 


class MyStack{
private:
    int arr[1000];
    int top;
    
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};

void MyStack ::push(int x) {
    // Your Code
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if (top == -1) return -1;
    int x = arr[top];
    top--;
    return x;
}