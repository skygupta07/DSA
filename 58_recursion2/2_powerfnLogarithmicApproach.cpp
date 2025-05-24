#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to calculate power (base^power) using Exponentiation by Squaring
    double power(double base, int power) {
        // Agar base 0 hai, toh answer bhi 0 hoga
        if (base == 0) return 0.0; // waah 0 ko double karne ke liye.. 0.0 kar diya..
        
        // Koi bhi number ki power 0 ho toh answer hamesha 1 hota hai
        if (power == 0) return 1.0;
        
        double ans = 1.0; // Final answer store karne ke liye variable
        
        // Agar power negative hai toh base ko 1/base kar dena hai 
        // taki exponentiation sahi kaam kare
        if (power < 0) base = 1 / base;
        
        // Power ka absolute value lena hoga taaki iteration sahi se ho
        power = abs(power); 
        
        // Exponentiation by squaring technique use kar rahe hain
        while (power) {
            // Agar power even hai toh base ka square le sakte hain aur power ko half kar sakte hain
            
            if (!(power & 1)) {  // power % 2 == 0
                base *= base;    // Base ka square kar do
                power /= 2;      // Power ko half kar do
            } 

            else { // Agar power odd hai toh answer me ek extra base multiply karna padega
                ans *= base;
                power--; // Ek power kam karke even banayenge
            }
        }
        
        return ans; // Final result return karna
    }
};
