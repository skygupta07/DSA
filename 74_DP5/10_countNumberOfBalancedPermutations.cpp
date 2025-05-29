#include <bits/stdc++.h>
using namespace std;

/*

You are given a string num. A string of digits is called balanced if the sum of the digits at even 
indices is equal to the sum of the digits at odd indices.


Return the number of distinct permutations of num that are balanced.

Since the answer may be very large, return it modulo 109 + 7.

A permutation is a rearrangement of all the characters of a string.
 

Example 1:

Input: num = "123"
Output: 2

Explanation:

The distinct permutations of num are "123", "132", "213", "231", "312" and "321".
Among them, "132" and "231" are balanced. Thus, the answer is 2.
Example 2:

Input: num = "112"
Output: 1

Explanation:

The distinct permutations of num are "112", "121", and "211".
Only "121" is balanced. Thus, the answer is 1.
Example 3:

Input: num = "12345"
Output: 0

Explanation:

None of the permutations of num are balanced, so the answer is 0.
 

Constraints:

2 <= num.length <= 80
num consists of digits '0' to '9' only.

*/

class Solution {

    // Global constant: large prime mod value for modular arithmetic
    static const int mod = 1e9 + 7;

    // Using long long for big factorial computations
    using ll = long long;

    // Arrays to store factorials, inverse elements, and inverse factorials
    vector<ll> fact, inv, invFact;

    // 🔁 Precompute factorials and inverse factorials for n in O(n)
    void precompute(int n) {
        // fact[i] = i!
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) 
            fact[i] = fact[i - 1] * i % mod;

        // inv[i] = modular inverse of i using Fermat's Little Theorem
        inv.assign(n + 1, 1);
        for (int i = 2; i <= n; i++) 
            inv[i] = mod - (mod / i) * inv[mod % i] % mod;

        // invFact[i] = (i!)^(-1) % mod
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) 
            invFact[i] = invFact[i - 1] * inv[i] % mod;
    }

public:
    int countBalancedPermutations(const string &s) {

        int n = s.size(), sum = 0;

        // Step 1: Calculate total sum of digits
        for (char c : s) 
            sum += c - '0';

        // If total sum is odd, it's impossible to split into two equal parts
        if (sum % 2 == 1) return 0;

        // Step 2: Precompute factorials and modular inverses up to n
        precompute(n);

        int halfSum = sum / 2;
        int halfLen = n / 2;

        // dp[i][j] = number of ways to select j digits whose sum is i
        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLen + 1, 0));
        dp[0][0] = 1;  // Base case: 0 digits, sum = 0 → 1 way

        // Step 3: Count frequency of each digit (0-9)
        vector<int> digits(10);
        for (char c : s) {
            int d = c - '0';
            digits[d]++;

            // Update dp in reverse to avoid reusing digits in same iteration
            for (int i = halfSum; i >= d; i--) {
                for (int j = halfLen; j > 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod;
                }
            }
        }

        // dp[halfSum][halfLen] gives number of valid combinations for one half
        ll res = dp[halfSum][halfLen];

        // Multiply by permutations of both halves → fact[halfLen] * fact[n - halfLen]
        res = res * fact[halfLen] % mod * fact[n - halfLen] % mod;

        // Divide by factorials of duplicate digits to avoid overcounting
        for (int i : digits) 
            res = (res * invFact[i]) % mod;

        return res;
    }
};




/*

 Logic Flow:
✅ Check Validity:
If the total sum of digits is odd, not possible to split into two equal sums → return 0.

🧮 Precomputation:
Calculate factorials, inverse factorials for combinatorics.

🧠 DP Solution:
dp[i][j] → Number of ways to pick j digits that sum up to i.

🔢 Counting Valid Halves:
Use DP to compute number of such valid halves (halfSum, halfLen).

🔁 Permutations:
Multiply valid half counts by permutations of each half (fact[halfLen] * fact[n - halfLen]).

❗ Avoid Overcounting:
Use inverse factorials for repeated digits to avoid duplicate permutations.

⏱️ Time Complexity:
O(n * halfSum * halfLen) → for the DP table
O(n) → for factorial precomputation

So overall: O(n^3) in worst case (since halfSum and halfLen ≈ n)


📦 Space Complexity:
O(n^2) → for DP table
O(n) → for factorial arrays

*/