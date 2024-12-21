#include <iostream>
#include <stack>
using namespace std;

class Stack{   
    // in general class Name ka first letter capital rakho..
    // by default data structures are defined in lower case in programming...
 
   // data members ko private rakhta hu and fns ko public

private:

    int *arr;  // important to declare array as pointer since arrays are always always passed by reference
    int top;
    int capacity;

public:
    //constructor
    Stack(int c){
        this->capacity = c;
        arr = new int[c];  // array banai..
        this->top = -1; // initially top ko -1 pe rakho...jab bhi then element add karna
                    // hoga to PEHLE top ko increment karo then add karo..        
    }


   // chalo stack ke to kucch specific fn hai jinhe mai jaanta hu to....chalo inhe to
   // member function ki tarah use kar leta hu... 
    void push(int data){
        // push karne se pehle overflow ki condition check karo..
        if (top == this->capacity-1){   //agar last idx pe aagya to phir next element
            // ke liye pehle increment jab karoge to array ke bahar chala jayega..
            cout<<"overflow";
            return;
        }
        this->top++; // pehle top ko increment kiya then usme value add ki...
        this->arr[top]= data;
    }
    // waise jab hum yaha member fn likh rahe hai to no need to write this->
    // but following due to standard procedure...

    int pop(){  // pop fn ki speciality ki wo return karta hai popped value...
        // pop karne se pehle underflow ki condition check kar lo pehle..
        if (this->top==-1){
            cout<<"underflow";
            return INT_MIN; 
        }
        cout<<"element to be popped is: "<<top<<endl;
        top--;
    }

// user ke liye mind picture stack ki tarah honi chahiye...
    void display(Stack st){
        int curr_pos = 0;
        while(curr_pos!=capacity-1){
            cout<<arr[curr_pos]<<" ";
            curr_pos++;
        }
    }

    void isEmpty(){
        if (this->top==-1){
            cout<<"stack is empty.\n";
        }
        else cout<<"stack is not empty\n";
    }

    void isFull(){
        if (this->top == (capacity -1)){
            cout<<"stack is full\n";
        }
        else cout<<"stack is not full.\n";
    }

    void getTop(Stack st){
        if (top==-1){
            cout<<"stack underflow"<<endl;
        }
        cout<<arr[top]<<endl;
    }
};

// push(), pop(), display(), isEmpty(), isFull(), topElement()


int main(){
    // class to bana li now main function me ussey kaise use karu..
    // arey bhai agar class bani hai to main me us class ka object bhi to bana...
    Stack st(4);  //  4 size ka stack banaya...
                    // stack class ka ek object banaya jiska naam st hai..
    st.push(2);
    st.push(5);
    st.push(7);
    st.pop();
    st.push(6);
    st.push(34);
    
    st.isEmpty();
    st.isFull();
    st.getTop(st);
    
    st.display(st);
}

/*

In Object-Oriented Programming (OOP), the -> operator is commonly known as
the member access operator or arrow operator. It is used in languages like C++ 
to access members (such as methods or properties) of a class or struct through a pointer

*/