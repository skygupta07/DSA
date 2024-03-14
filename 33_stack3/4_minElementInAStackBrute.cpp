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


