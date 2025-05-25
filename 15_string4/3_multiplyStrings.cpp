// multiplyStrings.cpp

/*

Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.


Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"


Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        // Agar dono me se koi bhi number "0" ho, toh seedha "0" return kar do
        if (num1 == "0" || num2 == "0") return "0";
        
        // Yahan ek vector banaya hai jo max digits store kar sake
        // num1.size() + num2.size() tak size rakha, kyunki product itna lamba ho sakta hai
        vector <int> num(num1.size() + num2.size(), 0);
        
        // Ab multiplication karna start karenge, ek-ek digit multiply karke
        for (int i = num1.size() - 1; i >= 0; i--) { // num1 ke har digit ke liye
            for (int j = num2.size() - 1; j >= 0; j--) { // num2 ke har digit ke liye
                // Pehle dono digits ko multiply kiya aur result ko vector ke correct index me add kiya
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                
                // Carry handle karte hain, agar result 10 se bada hai
                num[i + j] += num[i + j + 1] / 10; // Carry ko ek digit piche add kar diya
                num[i + j + 1] %= 10; // Current digit ko 10 ke mod se update kiya
            }
        }
        
        // Leading zeroes ko skip karte hain
        int i = 0;
        while (i < num.size() && num[i] == 0) i++;
        
        // Ab vector ke digits ko string me convert karte hain
        string res = "";

        // Ek ek karke digit ko string me push kiya...
        while (i < num.size()) res.push_back(num[i++] + '0');
        
        return res; 
    }
};
