#include <bits/stdc++.h> 
using namespace std;


void solve(stack <int> &myStack, int x){
    
    if (myStack.empty()){
        myStack.push(x);
        return;
    }


    int holdVariable = myStack.top();
    myStack.pop();

    solve(myStack,x);

    myStack.push(holdVariable);

}



stack <int> pushAtBottom(stack <int> &myStack, int x){
    
    solve(myStack,x);
    return myStack;

}








