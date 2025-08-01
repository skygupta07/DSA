#include <bits/stdc++.h>
using namespace std;


int toggleIthBit(int x, int i){
    x = x ^ (1 << i);
}



int main() {
    int x = 38494;
    int i = 7;

    toggleIthBit(x, i);
    
}