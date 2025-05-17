#include <bits/stdc++.h>
using namespace std;

class QueueUsingStacks {
private:
    // data members
    stack<int> st1, st2;
    
public:
    // member functions

    // Enqueue operation
    void enqueue(int el) {
        st1.push(el);
        return;
    }

    // Dequeue operation
    int dequeue() {
        if (st2.empty()) {
            if (st1.empty()) {
                // Queue is empty
                cout << "Queue is empty\n";
                return -1;
            }
            // Move elements from st1 to st2
            while (!st1.empty()) {
                int tp = st1.top();
                st1.pop();
                st2.push(tp);
            }
        }
        int deqVal = st2.top();
        st2.pop();
        return deqVal;
    }

    // Get the front element
    int getFront() {
        if (st2.empty()) {
            if (st1.empty()) {
                cout << "Queue is empty\n";
                return -1;
            }
            // Move elements from st1 to st2
            while (!st1.empty()) {
                int tp = st1.top();
                st1.pop();
                st2.push(tp);
            }
        }
        return st2.top();
    }

    // Get the rear element
    int getRear() {
        if (st1.empty() && st2.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        if (!st1.empty()) {
            return st1.top(); // Rear is at the top of st1
        }
        // If st1 is empty but st2 is not
        return st2.bottom();
    }

    // Check if the queue is empty
    bool isEmpty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    QueueUsingStacks q;

    // Check if the queue is empty initially
    if (q.isEmpty()) {
        cout << "Queue is empty\n";
    }

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    // Dequeue one element
    q.dequeue();

    // Get the front element
    cout << "Front element: " << q.getFront() << "\n";

    // Get the rear element
    cout << "Rear element: " << q.getRear() << "\n";

    // Check if the queue is empty again
    if (q.isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }

    return 0;
}



// implement queue using stack Leetcode

class MyQueue {
public:
    stack <int> st;
    stack <int> helper;
    MyQueue() {
        // leave it as it is no need
    }
    
    void push(int x) {
        st.push(x);    
    }
    
    int pop() {
        while (st.size()>0){ // empty st into helper
            int x = st.top();
            st.pop();
            helper.push(x);
        }
        int y = helper.top();
        helper.pop();
        while (helper.size()>0){
            int z = helper.top();
            helper.pop();
            st.push(z);
        }
        return y;
   
    }
    
    int peek() {
         while (st.size()>0){ // empty st into helper
            int x = st.top();
            st.pop();
            helper.push(x);
        }
        int y = helper.top();
        
        while (helper.size()>0){ // empty helper into st
            int z = helper.top();
            helper.pop();
            st.push(z);
        }
        return y;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */