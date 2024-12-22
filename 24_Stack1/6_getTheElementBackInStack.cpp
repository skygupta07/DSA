#include <bits/stdc++.h>
using namespace std;

void displaySt(stack <int> &st){
    stack <int> temp;

    while (!st.empty()){
        int x = st.top();
        st.pop();
        cout<<x<<" ";

        temp.push(x);
    }

    while (!temp.empty()){
        int y = temp.top();
        temp.pop();
        st.push(y);
    }
    cout<<"\n";
}


int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    displaySt(st);  
    st.push(7);
    displaySt(st);  
}
