#include <iostream>
using namespace std;

int hcf(int a, int b){              // T.C. = O(min(a,b))
    for (int i=min(a,b); i>=2; i--){
        if (a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

int main(){
    int a = 4;
    int b = 21;
    cout<<hcf(a,b);
}


/*
hcf (a,b) <= min(a,b)       hcf = 1 min.
lcm (a,b) >= max(a,b)       lcm = product of numbers max.
*/