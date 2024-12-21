#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> q;
    // c++ provides front pop push back size empty also -> ha ha sab chotte hi hai..
    // to po push agar peeche jagah khali hai...

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.empty()<<endl; // returns bool
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl; 
}   

