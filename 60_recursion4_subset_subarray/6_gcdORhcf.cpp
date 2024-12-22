#include <iostream>
using namespace std;

int gcd(int a, int b){ // T.C. = O(min(a,b))
    for (int i = min(a, b); i >= 2; i--){
        if ( (a % i == 0) && (b % i == 0)){
            return i;
        }
    }
    return 1;
}

int main(){
    cout << gcd(4,28);
}

/*
 (a,b) <= min(a,b)        = 1 min.
lcm (a,b) >= max(a,b)       lcm = product of numbers max.
*/