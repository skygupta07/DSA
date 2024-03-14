#include<iostream>
using namespace std;

int fib(int n){
    if (n==0 || n==1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    for (int i=0; i<10; i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;    
}



/*
when i am increasing number of i then it is taking a lot of compute hence we need to 
memoize it...

f(n) => function signature
-> recursion mai hum maan lete hai ki hamara answer wo laake de dega just like we did in
pmi(principle of mutual induction)

-> writing recursion solution mathematically is recurrence relation

*/
// 0 1 1 2 3 5 8 13 21 
