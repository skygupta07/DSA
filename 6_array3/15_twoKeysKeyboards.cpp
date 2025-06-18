// 2KeysKeyboard.cpp

/*

There is only one character 'A' on the screen of a notepad. 
You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.

Given an integer n, return the minimum number of operations to get the character 'A' 
exactly n times on the screen.
 

Example 1:

Input: n = 3
Output: 3

Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.


Example 2:

Input: n = 1
Output: 0
 

Constraints:

1 <= n <= 1000

*/



#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minSteps(int n) {
        // Base case: Agar already 1 'A' hai, to koi operation ki zarurat nahi
        if (n == 1) return 0;

        // Answer store karega minimum steps
        int ans = 0;

        // Start checking from smallest prime factor
        int i = 2;

        // Jab tak n > 1 hai, factorize karte raho
        while(i <= n) {

            // Agar i n ka factor hai (i.e. n divisible hai i se)
            if(n % i == 0) {
                // Ye kaam ka step hai:
                // -> iska matlab hum "Copy All" karenge (1 step)
                // -> fir i-1 times "Paste" karenge
                // -> Total i steps lagenge to multiply current A's by i
                ans += i;

                // Ab n ko divide kar do i se because ab humne i times increase kar liya
                n = n / i;
            } 
            
            else {
                // Agar i factor nahi hai to next number pe jao
                i++;
            }
        }

        // Final answer return karo
        return ans;
    }

};
