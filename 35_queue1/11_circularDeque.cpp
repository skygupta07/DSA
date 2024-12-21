#include <bits/stdc++.h>
using namespace std;


class MyCircularDeque {
public:
    vector<int> v;
    int front, back, sizee, capacity;

    MyCircularDeque(int k) {
        v = vector<int>(k, -1);
        front = 0;
        back = 0;
        sizee = 0; // Keeps track of the current number of elements
        capacity = k;
    }

// front mai tera pehle pointer thoda peeche hatega.. and then value daalega...
// back mai tera pehle daalega... phir back mai aage badhayega....

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        // Way - 01
        if (front == 0) {
            front = capacity - 1; // Wrap around to the end
        } 
        else {
            front--; // Simply decrement front
        }

        // Way  - 02
        // front--;
        // front = capacity + front;
        // front %= capacity;

        v[front] = value;

        sizee++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        v[back] = value;

        // Way - 01
        if (back == capacity - 1) {
            back = 0; // Wrap around to the beginning
        } 
        else {
            back++; // Simply increment back
        }

        // Way - 02
        // back++;
        // back %= capacity;

        sizee++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        v[front] = -1;

        // Way - 01
        if (front == capacity - 1) {
            front = 0; // Wrap around to the beginning
        } 
        else {
            front++; // Simply increment front
        }
        
        // Way - 02
        // front++;
        // front %= capacity;

        sizee--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (back == 0) {
            back = capacity - 1; // Wrap around to the end
        } 
        else 
        {
            back--; // Simply decrement back
        }
        v[back] = -1;
        
        sizee--;
        return true;
    }

    int getFront() {
        if (isEmpty()){return -1;}
        return v[front];
    }

    int getRear() {
        if (isEmpty()){return -1;}  // nalla 
        if (back == 0) {    // berojgar -> back rounded to home
            return v[capacity - 1]; // Wrap around to the last valid element
        } 
        else {  // chappri ❌ asli ✅
            return v[back - 1]; // Get the last element
        }
    }

    bool isEmpty() { return (sizee == 0); }

    bool isFull() { return (sizee == capacity); }
};


/*
object type design question 

1. means we have given more than one function which we need to implement...
2. input is dynamic (means size of input increase or decrease while running a single testcase)


constructor ka varnan teen line mai (level sabke niklenge)
1. have same name as Class
2. don't have return type
3. call once when an object of a class is created..


*/


