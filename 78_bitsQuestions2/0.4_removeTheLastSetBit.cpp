#include <bits/stdc++.h>
using namespace std;

void removeLastSetBit(int x){
    x = x & (x-1);
}


int main() {
    
    return 0;
}



/*

remove the last set bit ....



let me see one observation for number n and number n -1 


n ko n-1 mai convert karne ke liye rightmost 1 ko 0 karo then .... ukse aage ke right wale bits ko 1 karte jao...

and uske pehle ke bits to pehle jaise as it is hi rahenge....

*/