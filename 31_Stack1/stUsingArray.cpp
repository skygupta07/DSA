#include <iostream>
#include <stack> // stack follows 
using namespace std;

class Stack {
    public:
        int *arr;
        int top;
        int size;

    Stack (int size){  //stack declaration
        this -> size = size;
        arr = new int[size];
        top =-1;  // initialising top with -1

    }

    void push(int element){
        if ((size-top)>1){  // imp
            top++;  // pehle top ko increment karo then usme element push kar do
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<< endl;
        }
    }

    void pop(){
            if (top>=0){
                top--;   // chup chap ek index peeche kardo i.e. equivalent ki tumne wo element hi pop kar diya 

            }
            else{
                cout<<"stack underflow"<< endl;
            }
        }

        int peek(){
           if (top>=0){
            return arr[top];
           }

           else{
            cout<<"stack is empty"<<endl;
            return -1;  // kyuki function integer type ka banaya hai to kuch na kuch integer to at the end return 
                            // karna hi padega function ko
           } 
        }

        bool isEmpty(){
            if (top==-1){
                return true;
            }
            else return false;
        }
        
};

int main(){
    Stack s(5);   // Stack object of size 5 is created..
    s.push(1);
    s.push(3);
    s.push(6);
    s.push(8);
    s.push(34);
    

    s.pop();
    
    cout<<"element at the peek is: " << s.peek()<< endl;

    if (s.isEmpty()){
        cout<<"stack is empty.."<<endl;
    }
    else {
        cout<<"stack is not empty.."<<endl;
    }
    
}













