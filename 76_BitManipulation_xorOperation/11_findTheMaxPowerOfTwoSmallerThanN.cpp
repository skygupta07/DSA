#include <bits/stdc++.h>
using namespace std;


// maxPowerof two using function...

int maxPowerOfTwoSmallerThanN(int n){   // integer max 32 bit ka hi hoga..
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);

    return (n+1)>>1;    //2powerx -1  finally number aaya tha.. number mai ek jod ke 2 se divide kar diya...
}



int main(){
    int x = 78;
    int temp;

    while (x > 0){
        temp = x;   // just ek previous wala record rakhne ke liye..
        x = x & (x-1);
    }

    cout<<temp<<"\n";

    cout<<maxPowerOfTwoSmallerThanN(78)<<"\n";
    
} 



/*
most significant bit ko chodd ke then aage ke saare bits zero kar diya...

24 
1 1 0 0 0

ans = 16  (max power of 2 i.e. smaller than 24)

1 0 0 0 0


*/


/*
also to find the power of 2 just greater than num will be ..
        (maxPowerOfTwoSmallerThanN) * 2
*/