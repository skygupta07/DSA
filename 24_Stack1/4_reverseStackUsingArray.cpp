#include <bits/stdc++.h>
using namespace std;


// agar kewal stack ko kewal print hi karna hota to bas simply aap simply passed by value bhi 
// bhej sakte they...but agar reference se bheja hai to ..usko revert back bhi karna padega ..original position pe...

void displaySt(stack <int> &st){
    stack <int> temp;
    while (st.size() > 0){
        int x = st.top();
        st.pop();
        cout<<x<<"\n";
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
    vector <int> v;

    while (!st.empty()){
        int x = st.top();
        st.pop();

        v.push_back(x);
    }

    for (int i=0; i<v.size(); i++){
        st.push(v[i]);
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