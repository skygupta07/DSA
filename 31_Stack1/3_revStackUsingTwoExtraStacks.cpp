#include <bits/stdc++.h>
using namespace std;


// agar kewal stack ko kewal print hi karna hota to bas simply aap simply passed by value bhi 
// bhej sakte they...but agar reference se bheja hai to 
//..usko revert back bhi karna padega ..original position pe...

void displaySt(stack <int> &st){
    stack <int> temp;
    while (st.size() > 0){
        int x = st.top();
        st.pop();
        cout<<x<<" ";
        temp.push(x);
    }

    // reverting the stack to original stack...
    while (!temp.empty()){
        int x = temp.top();
        temp.pop();

        st.push(x);
    }

    cout<<"\n";
}

void reverseSt(stack <int> &st){
    stack <int> temp1;
    stack <int> temp2;

    while (!st.empty()){
        int x = st.top();
        st.pop();

        temp1.push(x);
    }

    while (!temp1.empty()){
        int x = temp1.top();
        temp1.pop();
        temp2.push(x);
    }

    while (!temp2.empty()){
        int x = temp2.top();
        temp2.pop();
        st.push(x);
    }
}




int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    displaySt(st);

    reverseSt(st);

    displaySt(st); 

    return 0;
}