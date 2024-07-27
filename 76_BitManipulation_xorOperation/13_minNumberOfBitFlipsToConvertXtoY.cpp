#include <bits/stdc++.h>
using namespace std;


int main(){
    int x = 45;
    int y = 89;
    int minFlips = __builtin_popcount(x^y);
    cout<<minFlips<<"\n";
}



/*

i.e. we have to detect number of different bits....
xor operation ek number dega... jisme wahi bit 1 hoga jisse change ki need hogi..

that is the problem reduces to find the number of set bits in xor of x and y..

*/