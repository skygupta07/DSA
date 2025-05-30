#include <bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &st, int x){
    if (st.empty()){
        st.push(x);
        return;
    }

    int hold = st.top();
    st.pop();

    insertAtBottom(st,x);
    st.push(hold);
}


void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    
    int x = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,x);
}


int main(){
    
}
