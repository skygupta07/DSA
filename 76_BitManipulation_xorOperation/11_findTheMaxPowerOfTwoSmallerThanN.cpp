#include <bits/stdc++.h>
using namespace std;


// Function to find the highest power of 2 that is smaller than the given number n
int maxPowerOfTwoSmallerThanN(int n) {   
    // Assume n is a 32-bit integer

    // Step 1: Yeh step ensure karega ki n ke rightmost '1' ke baad jitne bhi bits hai, sab 1 ban jaaye
    n = n | (n >> 1);  // Right shift karke OR karne se rightmost 1 ke adjacent bit bhi 1 ban jayega
    n = n | (n >> 2);  // Phir se 2-bit shift karke OR karne se aur bhi zyada 1s spread ho jayenge
    n = n | (n >> 4);  // 4-bit shift se 1s aur bhi aage spread ho jayenge
    n = n | (n >> 8);  // 8-bit shift se aur bhi zyada 1s set ho jayenge
    n = n | (n >> 16); // 16-bit shift se 32-bit tak ke saare 1s spread ho jayenge

    // Ab n ka final form: 2^x - 1 (matlab ek complete set bits ka form ban gaya)
    
    // Step 2: (n + 1) se ek step aage le gaye jo exactly ek power of 2 hoga
    // Phir usko right shift karke 2 se divide kar diya, jo max power of 2 hoga
    return (n + 1) >> 1;    
}




int main(){
    int x = 78;
    int temp;

    // method 2
    while (x > 0){
        temp = x;   // just ek previous wala record rakhne ke liye..
        x = x & (x-1);
    }

    cout<<temp<<"\n";

    cout<<maxPowerOfTwoSmallerThanN(78)<<"\n";
    
} 



/*


When x finally becomes 0, temp holds the value of x with only the most significant 1 bit still set.
This temp is the largest power of 2 smaller than or equal to x.
most significant bit ko chodd ke then aage ke saare bits zero kar diya...


24 
1 1 0 0 0

ans = 16  (max power of 2 i.e. smaller than 24)

1 0 0 0 0


*/


/*
also to find the power of 2 just greater than num will be ..
        (maxPowerOfTwoSmallerThanN) * 2
*/