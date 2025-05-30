#include <bits/stdc++.h>
using namespace std;

/*

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.

boolean insertFront() Adds an item at the front of Deque. 
Returns true if the operation is successful, or false otherwise.

boolean insertLast() Adds an item at the rear of Deque. 
Returns true if the operation is successful, or false otherwise.

boolean deleteFront() Deletes an item from the front of Deque. 
Returns true if the operation is successful, or false otherwise.

boolean deleteLast() Deletes an item from the rear of Deque. 
Returns true if the operation is successful, or false otherwise.

int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.

boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 
Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", 
"insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]

[[3], [1], [2], [3], [4], [], [], [], [4], []]

Output
[null, true, true, true, false, 2, true, true, true, 4]


Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, 
getRear, isEmpty, isFull.

*/


class MyCircularDeque {
public:

    vector <int> v;
    int front, back, sizee, capacity;

    MyCircularDeque(int k){

        v = vector <int> (k, -1);

        front = 0;
        back = 0;
        
        sizee = 0; // Keeps track of the current number of elements
        capacity = k;

    }

// front mai tera pehle pointer thoda peeche hatega.. and then value daalega...
// back mai tera pehle daalega... phir back mai aage badhayega....

    bool insertFront(int value){

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
        
        if (isFull()) return false;
        

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

        if (isEmpty()) return false;
        
        if (back == 0) back = capacity - 1; // Wrap around to the end
        
        else back--; // Simply decrement back
        


        v[back] = -1;
        
        sizee--;
        return true;

    }

    int getFront() {

        if (isEmpty()) {return -1;}
        return v[front];

    }

    int getRear() {

        if (isEmpty()) return -1;  // nalla 

        if (back == 0) {    // berojgar -> back rounded to home
            return v[capacity - 1]; // Wrap around to the last valid element
        } 

        else {  // chappri ❌ asli ✅
            return v[back - 1]; // Get the last element
        }
    }

    bool isEmpty()  return (sizee == 0); 

    bool isFull() { return (sizee == capacity); }
    
};


/*

💡 Object Type Design Question:
Is type ke question me multiple functions diye hote hain jinko implement karna hota hai 
(jaise add, remove, get, etc.).

Input ka size dynamic hota hai — yaani ek hi test case ke dauraan input bada ya chhota ho sakta hai 
(runtime me data change hota hai).

🧱

Constructor ka Varnan (3 Line Me - Level Sabke Niklenge):

Constructor ka naam class ke naam ke jaisa hi hota hai.
Iska koi return type nahi hota – na void, na kuch aur.
Object banate hi constructor ek baar automatically call ho jaata hai.

*/

