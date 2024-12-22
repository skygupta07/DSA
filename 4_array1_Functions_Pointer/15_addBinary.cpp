#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        int i = n1 - 1; // Pointer for s1
        int j = n2 - 1; // Pointer for s2
        
        string ans = ""; // Result string
        int carry = 0;   // Carry for addition
        
        // Process both strings from the end
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Start with carry
            
            if (i >= 0) sum += s1[i--] - '0'; // Add digit from s1
            if (j >= 0) sum += s2[j--] - '0'; // Add digit from s2
            
            // Append the binary digit (sum % 2) to the result
            ans += (sum % 2) + '0';
            
            // Update carry (1 if sum >= 2)
            carry = sum / 2;
        }
        
        // Reverse the result as we constructed it backward
        reverse(ans.begin(), ans.end());
        
        // Simplified leading zero removal
        ans.erase(0, ans.find_first_not_of('0'));
        if (ans.empty()) ans = "0"; // Handle all-zero case
        
        return ans;
    }
};

