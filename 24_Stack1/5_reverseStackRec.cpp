#include <bits/stdc++.h>
using namespace std;

void displaySt(stack <int> &st){
    stack <int> temp;

    while (!st.empty()){
        int x = st.top();
        st.pop();
        cout<<x<<"\n";

        temp.push(x);
    }

    while (!temp.empty()){
        int y = temp.top();
        temp.pop();
        st.push(y);
    }
    cout<<"\n";
}



void reverseStRev(stack <int> &st){
    // base case 
    if (st.size() == 0) return;


    int x = st.top();
    st.pop();

    // fn call 
    reverseStRev(st);


    // aate waqt kaam 
    cout<<x<<"\n";

    st.push(x);

}   // t


int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    displaySt(st);
    reverseStRev(st);
    cout<<"\n";
    displaySt(st);

}