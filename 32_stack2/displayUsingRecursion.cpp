#include<iostream>
#include<stack>
 
using namespace std;

void print(stack <int> &st){
    stack <int> temp;
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    while (temp.size()>0){
        st.push(temp.top());  // taki stack ke elements dubara usme daal saku..
        temp.top();
    }
    cout<<endl;
}

void displayRev(stack <int> &st){
    if (st.size() == 0) return;  // base case

    int x = st.top();
    cout<<x<<" "; //kaam
    
    st.pop(); 
    
    displayRev(st); // fn call
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
    stack <int> st;  //inbuilt stack used...
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);  
    st.push(5);
    st.push(6);


    display(st);
    cout<<endl;
    displayRev(st);
    cout<<endl;

}


// t.c. =O(n), s.c. = O(n)
// arey wo call stack ke kaaran (4 boxes explanation)
// arey abhi to function khatam hi nahi hua ispe dot lagao then next fn call pe dhyan do..


