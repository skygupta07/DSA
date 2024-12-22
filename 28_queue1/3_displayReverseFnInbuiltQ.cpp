#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void display(queue <int> &q){   // by reference
    int n=q.size();    // v.size(); same operations like vectors also
    for (int i=0; i<n; i++){    // t.c. O(n) , s.c. = O(1)
        int x = q.front();  
        cout<<x<<" ";
        q.pop();
        q.push(x); // apni queue ko bhi to maintain karte hue chalna hai..
    }
    cout<<endl;
    // display karne ke liye har ek front element ko pakda x mai store kara x ko print kara 
    // q se pop kiya (obviously front) then x ko queue mai push kiya...
    // yahi itne se kaam karne ke liye stack mai bahut bakchodi thi...ek alag stack banao..
}


void reverse(queue <int> &q){ // reversing queue using stack
    int n=q.size(); // similar to vectors like v.size()
    stack <int> st;
    while (q.size()>0){
        int x=q.front(); // kabhi bhi queue ke front ko ek x mai
                                // nikala karo...
        q.pop();
        st.push(x);           // front pop push (in queue)
    }
    //now empty the stack into queue
    while(st.size()>0){
        int x=st.top(); // top pop push (in stack)
        st.pop();
        q.push(x); 
    }
}


int main(){
    queue <int> q;  // vector <int> v;  === dataStructuretype <data type> nameGivenTodataStructure
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    display(q);
    q.pop();
    cout<<q.size()<<endl;
    display(q); 
    cout<<q.size()<<endl; 
}
// queue: 
// fifo = first in first out    fcfs = first come first serve...

/*
inbuilt functions ko hum q.pop() dot operator ka use karke bulaate hai...
*/