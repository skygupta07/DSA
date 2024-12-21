#include <iostream>
#include <stack>

// implementing stack using standard library..
using namespace std;
int main(){
    stack <int> s;
    s.push(3);
    s.push(5);
    s.push(9);
    s.pop();
    s.push(14);
    s.push(17);
    s.pop();
    s.push(19);
    s.push(27);
    cout<<"top element of stack is: " <<s.top()<< endl;
    
    if (s.empty()) cout<<"stack is empty..."<< endl;
    else cout<<"stack is not empty..."<< endl;
    
    cout<<"size of stack is: "<<s.size()<< endl;


    while (!s.empty()){
        int tp = s.top();
        s.pop();
        cout<<tp<<" ";
    }

    cout<<s.top()<<"\n";


}