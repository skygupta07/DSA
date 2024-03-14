#include <iostream>
#include <vector>
using namespace std;

class Queue{
public:
    int f;  // front
    int b;  // back
    vector <int> arr;   // vector wearing array clothes to mimic
                        // important to first declare outside 

    Queue(int size){ // constructor
        f=0;    // bhai array ki help se bana rahe hai...
        b=0; // initially to front aur back arr ke zeroth index pe 
        vector <int> v(size);  // vector used so that we can easily find size in between
        arr = v;
    }


    void push(int val){
        if(b == arr.size()){
            cout<<"queue is full"<<endl;
            return;
        }
        arr[b]=val; // nahi to array ke back wale index pe value insert kar di
        b++;    // making back index ready for next...
    }

    void pop(){
        if (b==0){
            cout<<"queue is Empty can't pop"<<endl;
            return;
        }
        f++;
    }

    void front(){
         if (b==0){
            cout<<"queue is Empty can't get front"<<endl;
            return;
        }
        cout<<arr[f]<<endl;
    }

    void back(){
        if (b==0){
            cout<<"queue is Empty can't get back"<<endl;
            return;
        }
        cout<<arr[b-1]<<endl;   
    }

    void size(){
        cout<<b-f<<endl;    // asked by nitin
                               // back hamesha ek position aage rehta hai...
    }

    bool isEmpty(){
        if (b==0) return true;
        else return false;
    }

    void display(){
        for (int i=f; i<b; i++){    // i know only front(including) to back(excluding) 
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    //push pop front back size empty

    Queue q(5);  // dynamically creating queue of size 5 using user defined Queue class
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.display();
    q.push(5);
    q.display();    // inbuilt fn use karne ke liye ya class mai member fn
                    // ko use karne ke liye... we use dot operator

    q.push(6);
    q.push(7);
    

}


/*
problems in array implementation of q
1. wastage of space -> solution is circular array....




*/