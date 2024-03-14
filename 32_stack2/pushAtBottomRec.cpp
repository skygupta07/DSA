#include<iostream>
#include<stack>

using namespace std;

void display(stack <int> &st){
    if(st.size()==0){  // base case
        return;
    }
    int x = st.top();
    cout<<x<<" ";  // kaam ->     
    st.pop();       //yes brother kaam more than one line ka ho sakta hai...

    display(st);   // call   (fn calling itself)
      // apne stack me elements push kiye again...

    st.push(x);

}

void pushAtBottom(stack<int> &st, int n){
    // jab tu display kar rha tha recursively just the same code hai bas ab yaha base case me fn return karne se pehle chup chap
    // jaldi se us element ko push kar do...
    if(st.size()==0){ 
        st.push(n);                    // base case
        return;
    }
    int x = st.top();
    
    
    st.pop();
    pushAtBottom(st,n);   // call   (fn calling itself)
      // apne stack me elements push kiye again...

    st.push(x);
}
int main(){
    stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    display(st);
    cout<<endl;
    pushAtBottom(st, 13);
    display(st);


    
}