#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:

    int f;  // front index
    int b;  // back index
    int s;  // current size

    int capacity; // maximum capacity
    vector <int> arr;  // vector for storing elements

    CircularQueue(int size) {   // constructor
        f = 0;
        b = 0;
        s = 0;

        capacity = size;
        arr = vector<int>(size);  // initializing vector with the given size
    }

    // Check if the queue is full
    bool isFull() {
        return s == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s == 0;
    }

    // Push an element to the back of the queue
    void push(int val) {

        if (isFull()) {
            cout << "Queue is full. Cannot push " << val << endl;
            return;
        }

        arr[b] = val;
        b = (b + 1) % capacity;  // Move back pointer circularly hamesha hi 
        // b = b+1 nahi karte hum simply hi... %capacity ka tarka laga dete 
        // h to identify chor ki dadhi mai tinka...
        
        s++;
    }

    // Pop an element from the front of the queue
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop" << endl;
            return;
        }

        f = (f + 1) % capacity;  // Move front pointer circularly {ye modulus karne wali trick mene sabse pehle 
        // yahi seekhi thi....}

        s--;
    }


    // Get the front element
    void front() {

        if (isEmpty()) {
            cout << "Queue is empty. No front element" << endl;
            return;
        }

        cout << "Front element: " << arr[f] << endl;
    }

    // Get the back element
    void back() {

        if (isEmpty()) {
            cout << "Queue is empty. No back element" << endl;
            return;
        }

        int backIndex = (b - 1 + capacity) % capacity;  // Move back circularly to get the last inserted element
        cout << "Back element: " << arr[backIndex] << endl;

    }

    // Get the current size of the queue
    void size() {
        cout << "Current queue size: " << s << endl;
    }

    // Display the elements of the queue
    void display() {

        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";

        for (int i = 0; i < s; i++) {
            cout << arr[(f + i) % capacity] << " ";  // Print elements circularly
        }

        cout << endl;
    }
};


int main() {
    CircularQueue cq(5);  // Create a circular queue with capacity 5

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.display();  // Output: 10 20 30

    cq.front();    // Output: Front element: 10
    cq.back();     // Output: Back element: 30

    cq.push(40);
    cq.push(50);
    cq.display();  // Output: 10 20 30 40 50

    cq.push(60);   // Output: Queue is full. Cannot push 60

    cq.pop();
    cq.display();  // Output: 20 30 40 50

    cq.push(60);   // Wrap around and insert 60 at the front
    cq.display();  // Output: 20 30 40 50 60

    cq.front();    // Output: Front element: 20
    cq.back();     // Output: Back element: 60

    return 0;
}

/*
```

### Explanation:
1. **Constructor**: Initializes the queue with a specific size. The front (`f`), back (`b`), and size (`s`) are initialized to 0.
2. **push()**: Adds elements at the back of the queue. If the queue is full, it prints a message and doesn’t add any more elements. It moves the back pointer in a circular manner.
3. **pop()**: Removes the front element from the queue. It moves the front pointer circularly. If the queue is empty, it prints a message.
4. **front()**: Retrieves the front element if the queue is not empty.
5. **back()**: Retrieves the back element. The back index is adjusted to account for the circular nature of the queue.
6. **display()**: Displays the elements in the queue from front to back by iterating over the valid elements in the circular buffer.

### Example Output:
```
Queue elements: 10 20 30 
Front element: 10
Back element: 30
Queue elements: 10 20 30 40 50 
Queue is full. Cannot push 60
Queue elements: 20 30 40 50 
Queue elements: 20 30 40 50 60 
Front element: 20
Back element: 60
```

### Key Points:
- The **wrap-around** behavior is handled using the modulo operator (`%`).
- The **front** and **back** pointers are adjusted circularly after every operation.
- The **capacity** of the queue is maintained to prevent overflow or underflow.



*/