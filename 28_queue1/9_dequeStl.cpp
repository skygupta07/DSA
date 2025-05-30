#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;

    // Insert elements at the back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Insert elements at the front
    dq.push_front(5);
    dq.push_front(1);

    // Print elements of deque
    cout << "Deque after push operations: ";
    for (int el : dq) {
        cout << el << " "; // Output: 1 5 10 20 30
    }
    cout << "\n";

    // Access the front and back elements
    cout << "Front element: " << dq.front() << endl; // Output: 1
    cout << "Back element: " << dq.back() << endl;   // Output: 30

    // Remove elements from the front
    dq.pop_front();
    cout << "Deque after pop_front(): ";
    for (int el : dq) {
        cout << el << " "; // Output: 5 10 20 30
    }
    cout << "\n";

    // Remove elements from the back
    dq.pop_back();
    cout << "Deque after pop_back(): ";
    for (int el : dq) {
        cout << el << " "; // Output: 5 10 20
    }
    cout << "\n";

    // Check the size of the deque
    cout << "Size of deque: " << dq.size() << endl; // Output: 3

    // Check if the deque is empty
    if (dq.empty()) {
        cout << "Deque is empty\n";
    } else {
        cout << "Deque is not empty\n"; // Output: Deque is not empty
    }

    // Access an element by index using at()
    cout << "Element at index 1: " << dq.at(1) << endl; // Output: 10

    // Clear all elements from the deque
    dq.clear();
    cout << "Deque size after clear(): " << dq.size() << endl; // Output: 0

    return 0;
}


/*

Standard deque Operations:
push_back(x): Adds an element x to the end of the deque.
push_front(x): Adds an element x to the front of the deque.

pop_back(): Removes an element from the end of the deque.
pop_front(): Removes an element from the front of the deque.

front(): Returns the element at the front of the deque.
back(): Returns the element at the back of the deque.

size(): Returns the number of elements in the deque.

empty(): Checks if the deque is empty.
clear(): Removes all elements from the deque.

at(index): Accesses the element at a specific position in the deque.


*/