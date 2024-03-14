#include<iostream>
using namespace std;

class Stack{
public:       // sorry class ke name ke aage fn call() wala lga diya...
    int arr[5];
    int top;

    Stack(){
        this->top = -1;
   }

   void push(int val){
        top++;  // pehle top ko increment karo then value assign karo...
        arr[top] = val;
   }

   int getTop(){
        return arr[top];
   }

   void pop(){
        if (top>0){
            top--;
        }
        else{
            cout<<"stack underflow."<<endl;
            return;
        }
   }


};


int main(){
    Stack st;
    st.pop();
    st.push(2);
    st.push(5);
    st.push(8);
    cout<<st.getTop()<<endl;

    

}