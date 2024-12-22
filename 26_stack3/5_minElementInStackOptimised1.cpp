#include <iostream>  // T.C. = O(n);
#include <stack>
using namespace std;

int minInStack(stack <int> st){
    int min = INT_MAX;
    stack <int> helper;
    
    while (st.size()>0){
        int x = st.top();
        if (x<min){
            min = x;
        }
        helper.push(x);
        st.pop();
    }
    
    // now min contains the min. element of stack st, but our stack has eventually become 
    // empty so fill st using helper

    while(helper.size()>0){
        int y = helper.top();
        st.push(y);
        helper.pop();
    }
    return min;
}





int main(){
    stack <int> st;
    st.push(1);
    st.push(3);
    st.push(6);
    st.push(8);
    st.push(10);
    st.push(-4);
    st.push(17);

    cout<<minInStack(st)<<endl;
    
    
}
// -------------------- -----      -------

class MinStack {
public:
    stack <int> st;
    stack <int> helper;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (helper.size()==0 || val<helper.top()){
            helper.push(val);
        }
        else{
            helper.push(helper.top());
        }
        
    }
    
    void pop() {    // pop from both..
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() { // O(1) since we are only returning the helper's top element
        return helper.top(); // it will be confirm that helper top is minimum element...
    }
};

// /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// Lc 155 -> min stack
/*
to do in O(1) time -> apply condition while pushing
1. push incoming element directly into st;
2. push in helper iff incoming is lesser than helper top else push the helper's top again

leetcode ke hi push pop fn mai modification kari

method3 -> implement the stack with vector...is also good
*/