#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionAddition(string s) {
        int n = s.length();
        int numerator = 0;  // yaha addition hoga.. final numerator
        int denominator = 1;    // since yaha multiplication hoga ... final denominator

        int i = 0;

        // sign numerator denominator
        while(i < n){
            int sign = 1;
            int num = 0;    // local numerator
            int den = 0; // bhy?
            
            // check sign and go ahead
            if (s[i] == '+' || s[i] == '-'){
                if (s[i] == '-') sign = -1;
                i++;
            }
            

            // form num and go ahead
            while (i<n && isdigit(s[i])){
                num = num*10 + s[i] - '0';
                i++;
            }

            // take care of num sign also
            num *= sign;

            i++;    //skipping division sign

            // form denominator and go ahead
            while (i<n && isdigit(s[i])){   // isdigit() expects a char as input , isdigit(s[i] - '0') mat kar dena jab inbuilt fn use kar hi rahe ho to...
            
                den = den*10 + (s[i] - '0');
                i++;
            }


            numerator = numerator*den + num*denominator;
            denominator *= den; 

            int hcf = __gcd(abs(numerator), denominator);
            numerator = numerator / hcf;
            denominator = denominator / hcf;
        }

        return to_string(numerator) + "/" + to_string(denominator);

    }
};