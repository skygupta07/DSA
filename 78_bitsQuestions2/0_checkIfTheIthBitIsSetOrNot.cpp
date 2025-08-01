#include <bits/stdc++.h>
using namespace std;

// using left shift operator 
/*
ek ith bit ke liye mask kind of banaya and then number pe and karke lagaya...
agar result positive aaya to => ith bit is set 
else not...
*/

bool ifIthBitSet(int x, int i){
    if (x & (1 << i)) return true;
    else return false;
}

// using right shift operator
/*
ab uss ith bit ko hi kinare pe le gaye and ab ussi se pucha ki ki hal h laadle ??
*/

bool isIthBitSet(int x, int i){
    if ((x >> i) & 1) return true;
    else return false;
}


int main() {
    
    bool result = ifIthBitSet(13, 2);

    cout<<result<<endl;
}


/*
kucch chutiye binary number mai bhi indexing left to right karte h...
always remember that indexing in binary is right to left always...

*/