//0 1 1 2 3 5 8 13 21 
// 0th first second third term

#include <iostream>
using namespace std;

int fib(int n){  // nth fibonacci number
    if (n==0 || n==1) return n;
    int a = 0;
    int b = 1;
    int c;
    for (int i=2; i<=n; i++){
        int c = a + b;
        a = b;
        b = c;

    }
    return b;   // imp
}


int main(){
    for (int i=0; i<=8; i++){
        cout<<fib(i)<<" ";
    }
    
}

//  0 1 1 2 3 5 8 13 21 34 55 89

// yes there is zeroth fibonacci number then first fibonacci , second fibonacci