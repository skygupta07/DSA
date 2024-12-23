#include <bits/stdc++.h>
using namespace std;

    // function to convert a given Gray equivalent n to Binary equivalent.
int grayToBinary(int n){
        int result = n;
        while (n>0){
            n = n>>1;   // right shift the number
            result = result ^ n;    // perform xor operation
        }
        return result;
}