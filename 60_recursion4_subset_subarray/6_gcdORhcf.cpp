#include <iostream>
using namespace std;


// T.C. = O(min(a,b))
int gcd(int a, int b){ 

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

// un dono mai se jo bhi chota element h waha se start hoga ... and i = 2 tak check karo...
// wo number i jo dono ko divide karega ... that will be gcd ...