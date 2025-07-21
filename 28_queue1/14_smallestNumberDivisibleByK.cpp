// smallestIntegerDivisibleByK.cpp

/*

Given a positive integer k, you need to find the length of the smallest positive integer n 
such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.
Note: n may not fit in a 64-bit signed integer.


Example 1:

Input: k = 1
Output: 1

Explanation: The smallest answer is n = 1, which has length 1.


Example 2:

Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.


Example 3:

Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
 

Constraints:

1 <= k <= 1e5

*/



#include <bits/stdc++.h>
using namespace std;

// using maths
class Solution {
public:

    int smallestRepunitDivByK(int k) {
        
        // Hum ek aise number N ko dhoondh rahe hain jo sirf 1s se bana ho (jaise 1, 11, 111, 1111, ...) 
        // aur N % k == 0 ho (yaani wo number k se divide ho jaaye).
        // Agar aisa koi number exist karta hai, to hum uski length (kitne 1s ka use hua) return karenge.

        // r: remainder after dividing current number by k
        // n: current number ki length (kitne 1s use hue ab tak)
        for (int r = 0, n = 1; n <= k; n++) {

            // r = (r * 10 + 1) % k
            // Ye step actually N ko build kar raha hai one-by-one digits me bina pura number store kiye.
            // Jaise agar pichle remainder r = 1 ho, to agla number 11 hoga -> (1 * 10 + 1) = 11
            // Hum directly number nahi bana rahe, sirf remainder calculate kar rahe hain.

            r = (r * 10 + 1) % k;

            // Agar kisi point pe remainder 0 aa gaya, matlab wo repunit number k se divide ho gaya.
            if (r == 0) return n; // to uski length return kar do.
        }

        // Agar k ke against koi bhi repunit number divide nahi ho raha,
        // to -1 return karo. Yeh kab hota hai? Jab k kisi aise factor ka multiple ho
        // jo 1s-only numbers ko kabhi divide nahi kar sakta — jaise agar k is even or divisible by 5.

        return -1;
    }

};





int lengthOfNumber(int k) {
    // If K is not positive, return -1 (invalid case)
    if (k <= 0) return -1;

    // Initialize variables
    queue <pair <int, int>> q; // Pair of (current remainder, length of the number)
    set <int> visited;        // To track visited remainders

    // Start with the first number '1'
    q.push({1 % k, 1});
    visited.insert(1 % k);

    // BFS-like approach
    while (!q.empty()) {

        auto [remainder, length] = q.front();
        q.pop();

        // If remainder is 0, we found the answer
        if (remainder == 0) return length;

        // Generate the next numbers by adding a digit '1'
        int nextRemainder = (remainder * 10 + 1) % k;

        // If this remainder has not been visited, enqueue it
        if (visited.find(nextRemainder) == visited.end()) {
            q.push({nextRemainder, length + 1});
            visited.insert(nextRemainder);
        }
    }

    // If no such number exists, return -1
    return -1;
}

int main() {
    int k;
    cin >> k;

    int result = lengthOfNumber(k);
    cout << result << endl;

    return 0;
}
