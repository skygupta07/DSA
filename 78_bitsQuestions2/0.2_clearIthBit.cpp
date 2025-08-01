#include <bits/stdc++.h>
using namespace std;


// 1 ko left shift kara i position, then negate karke ... and kar diya.. to
// simply clear the ith bit...

void clearIthBit(int x, int i){
    x = x & (~(1 << i));
}


int main() {
    int x = 15;
    int i = 4;

    clearIthBit(x, i);

}