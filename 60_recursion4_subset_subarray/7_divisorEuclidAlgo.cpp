#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (a == 0) return b;
    else return gcd(b % a, a);
}

// time complexity of gcd(a,b) = O(log(a+b))

int main()
{
    int a = 22;
    int b = 48;
    cout << gcd(a, b); // modulus operator handles both case of a<b or a>b
}

/*
1. long division method
2. the stage at which remainder becomes zero, then the divisor at that stage is required

*/