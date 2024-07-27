#include <bits/stdc++.h>
using namespace std;


string decimalToBinary(int n){
    string result = "";
    while (n > 0){
        if (n%2 == 0){
            result = "0" + result;
        }
        else{
            result = "1" + result;
        }
        n = n>>1;  // n = n/2
    }

    return result;
}




int main(){
    int decNum = 18;
    cout<<decimalToBinary(decNum);
}

/*
x>>1   => x mai divide hoga two power 1 se ..
x>>2   => x mai divide hoga tow power 2 se...

x>>K  => x = x/2powk

1<<3   => 1*2pow3

*/