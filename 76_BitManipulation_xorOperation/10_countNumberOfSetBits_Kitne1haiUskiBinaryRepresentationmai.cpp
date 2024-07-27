#include <bits/stdc++.h>
using namespace std;

int numOfSetBitsInBinaryOfDecimalNum(int n){
    int setBitCount = 0;
    while (n>0){
        n = n&(n-1);
        setBitCount++;
    }
    return setBitCount;
}


int main(){
    int numOfSetBits = __builtin_popcount(356);
    cout<<numOfSetBits<<"\n";

    int numOfSetBits2 = numOfSetBitsInBinaryOfDecimalNum(356);
    cout<<numOfSetBits2<<"\n";
}

/*
8 4 2 1
1 1 0 1  -> 3 set bits for 13

*/

/*
x aur x-1 ki binary representation mai ek cheej observe kara...
ek kaafi bada portion exactly same hai (maybe of zero length also) and baccha hua 
saara content dono number mai flipped hai....

x ki last set bit(observing obviously from left) and then ussey aage se maamla flip hota hai x-1 wale number mai..

flipped region mai x ke andar jo ek hi set bit tha usko hi eliminate karwa 
diya...



---- accha (brian kerniglen's algorithm) ----
x & (x-1)  karne se aapki ek last set bit eliminate ho jaati hai...

yahi cheej repeat karte jao... pata chal jaega .. kitne set bits hai.. number of repetitions se...

*/