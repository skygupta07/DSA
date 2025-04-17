#include <bits/stdc++.h>
using namespace std;

/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 
Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/

class MinStack {
public:
    stack<int> stk;       // Ye main stack hai jo saare elements ko store karega.
    stack<int> helper;   // Ye helper stack hai jo har step pe minimum element ko track karega.
    
    MinStack() {
        // Constructor, koi initialization ki zarurat nahi hai kyunki hum stacks already declare kar chuke hain.
        // aise mostly cases mai mene dekha h initialisation ki need padti nahi h.. issey ghabrana nahi h...
    }
    
    void push(int val) {
        // Main stack mein element ko push karo
        stk.push(val);
        
        // Helper stack mein minimum element ko track karte hain:

        // 1. Agar helper stack khali hai ya naya element (val) current minimum se chhota hai,
        //    toh usse helper stack mein push karenge.

        if (helper.size() == 0 || val < helper.top()) {
            helper.push(val);  // Naya element minimum hai, push kar do.
        } 

        // 2. Agar naya element current minimum se bada ya barabar hai,
        //    toh phir se current minimum (helper ka top) ko push karte hain.

        else {
            helper.push(helper.top());  // Same minimum ko dobara push karte hain.
        }
    }
    
    void pop() {
        // Dono stacks (main aur helper) se top element ko remove karte hain.
        // Ye isliye zaroori hai kyunki helper stack ka top bhi ussi element ka minimum hai.
        stk.pop();
        helper.pop();
    }
    
    int top() {
        // Main stack ka top return karte hain.
        return stk.top();
    }
    
    int getMin() {
        // Helper stack ka top return karte hain kyunki yahin pe minimum element hamesha stored rahega.
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();  // Ek naya MinStack object banate hain.
 * obj->push(val);                  // Stack mein val ko push karte hain.
 * obj->pop();                      // Stack se top element ko remove karte hain.
 * int param_3 = obj->top();        // Top element ko return karte hain.
 * int param_4 = obj->getMin();     // Minimum element ko return karte hain.
 */
