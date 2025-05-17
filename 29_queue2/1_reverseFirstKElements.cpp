// reverseFirstKElements.cpp

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void display(queue <int> qu){
    int n = qu.size();
    for (int i=0; i<n; i++){
        int x = qu.front();
        cout<<x<<" ";
        qu.pop();
        qu.push(x);
    }
    cout<<endl;    
}
 

void revQu(queue <int> &qu, int k){ // lets not preserve qu
    stack <int> st;
    // empty the whole queue into stack
    int n = qu.size();
    for (int i = 0; i<n; i++){
        int x = qu.front();
        qu.pop();
        st.push(x);
    }
    // push st into qu 
    while (st.size()>0){
        int y = st.top();
        st.pop();
        qu.push(y);
    }
    // pop from queue n-k times and push it into stack
    for (int i=0; i<n-k; i++){
        int z = qu.front();
        qu.pop();
        st.push(z);    
    }
    // push st element at the end of queue...
    while (st.size()>0){
        int x = st.top(); // top pop push 
        st.pop();
        qu.push(x);
    }

}


int main(){
    queue <int> qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.push(4);
    qu.push(5);
    qu.push(6);

    display(qu);
    revQu(qu,3); // reverse first 3 element of queue
    
    display(qu);    
} 

// reverse element of queue using stack
/*
ip: 1 2 3 4 5 6 , k = 3
op: 
to po push

*/  