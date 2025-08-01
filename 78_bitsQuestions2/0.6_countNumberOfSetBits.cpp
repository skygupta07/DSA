// last bit of odd number will always be one



#include <bits/stdc++.h>
using namespace std;


// to count the number of set bits .. .you just simply keep turning off the rightmost 
// set bit and increment the count..

int countSetBits(int x){
    int count = 0;

    while (x > 0){
        x = x & (x-1);
        count++;
    }

    return count;
}