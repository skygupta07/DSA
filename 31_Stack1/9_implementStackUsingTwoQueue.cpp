#include <bits/stdc++.h>
using namespace std;


class MyStack {

private:    // data members
    queue<int> q1;
    queue<int> q2;

public:
    // Constructor
    MyStack() {}

    // Push operation
    void push(int x) {
        q1.push(x);
    }

    // Pop operation
    int pop() {
        // Move elements to q2 until only one remains
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // The last element is the one to be popped
        int popped_element = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return popped_element;
    }

    // Top operation
    int top() {
        // Move elements to q2 until only one remains
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // The last element is the top element
        int top_element = q1.front();

        // Move it to q2 as well
        q2.push(q1.front());
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return top_element;
    }

    // Empty operation
    bool empty() {
        return q1.empty();
    }
};
