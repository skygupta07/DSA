#include<iostream>
#include<stack>
 
using namespace std;

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
      

    st.push(x);   // apne stack me elements push kiye again..
}


void reverse(stack <int> &st){
    if (st.size() == 0) return;  // base case

    int x = st.top();
    pushAtBottom(st,x);
    
    st.pop(); 
    
    reverse(st); // fn call
     //kaam  agar kaam baad me kiya to then fn traceback karte hue elements ko print karega..
    st.push(x);   // traceback karte hue stack me dubara se 1 2 3 4 5 6 dal jaega...
    
    // individual call stack ka personal x banega jo ki uss time ki value store kar ke rakhega
    // then jab fn traceback karega to sabki values milti jaegi...

}




void display(stack <int> &st){
    if (st.size() == 0) return;  // base case

    int x = st.top();
    
    
    st.pop(); 
    
    display(st); // fn call
     //kaam  agar kaam baad me kiya to then fn traceback karte hue elements ko print karega..
    
    cout<<x<<" ";
    st.push(x);   // traceback karte hue stack me dubara se 1 2 3 4 5 6 dal jaega...
    
    // individual call stack ka personal x banega jo ki uss time ki value store kar ke rakhega
    // then jab fn traceback karega to sabki values milti jaegi...

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
    
    cout<<endl;


    


}

// Reverse using Recursion me simply top element ko bottom me push karo and bacche hue elements
// ko recursion magic se Reverse i.e. fn repeats..








// t.c. =O(n), s.c. = O(n)
// arey wo call stack ke kaaran (4 boxes explanation)
// arey abhi to function khatam hi nahi hua ispe dot lagao then next fn call pe dhyan do..


