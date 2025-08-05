// countPrefixAndSuffixPairs2.cpp
// disliked question just glance only


#include <bits/stdc++.h>
using namespace std;


// still gave tle
class Solution {
public:
    // Modulo constant to avoid integer overflow in case of large answers
    const long long mod = 1e9 + 7;

    long long countPrefixSuffixPairs(vector<string>& words) {

        // freq map store karega kitni baar koi prefix-suffix string pehle aa chuki hai
        unordered_map<string, int> freq;

        long long count = 0; // Final answer store karega

        // Har word ko ek-ek karke process karenge
        for (string& word : words) {
            int n = word.length(); // current word ka length n

            // Har possible length ke liye prefix aur suffix check karenge
            for (int len = 1; len <= n; len++) {
                // Agar prefix (0 to len-1) == suffix (n-len to n-1)
                if (word.substr(0, len) == word.substr(n - len, len)) {

                    // Common prefix-suffix substring ko nikaal lo
                    string s = word.substr(0, len);

                    // Agar yeh s pehle kisi word ke form mein aa chuka hai,
                    // toh uski frequency add kar do answer mein
                    count = (count + freq[s]) % mod;
                }
            }

            // Ab current word ko freq map mein daal do
            // Taaki next words ke liye yeh word consider ho
            freq[word]++;
        }

        // Final answer return karo
        return count;
    }
};




class Solution {
public:

    // Z-function: Calculates length of longest substring starting at i that matches prefix
    // For string s = "ababa", z[2] = 3 means s[2..] = "aba" shares 3 chars with prefix "aba"
    vector <int> z_function(const string& s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);

            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;

            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }

        return z;
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        // freq stores frequency of each unique prefix (as a rolling hash)
        unordered_map <int64_t, int> freq; // int64_t or long long same hi baat h...
 
        long long ans = 0;
        const int64_t mod = (int64_t)1e17 + 3; // large prime mod for hash stability

        for (const string &w : words) {
            vector <int> z = z_function(w); // Get Z-array for current word

            int64_t hash = 0;

            // Let i = prefix length [1 to n]
            // We build the rolling hash on the fly for prefix of length i
            for (int i = 1, n = w.size(); i <= n; i++) {
                // Update hash for prefix w[0..i-1]
                hash = (hash * 27LL + (w[i - 1] - 'a' + 1)) % mod;

                // Now check if this prefix is also a suffix
                // We use Z-function:
                // z[n - i] == i means: suffix of length i == prefix of length i
                if (z[n - i] == i) {
                    // If prefix-suffix substring already seen, add its count
                    if (freq.count(hash)) ans += freq[hash];
                }

            }
            // Add full word hash to map for future matches
            freq[hash]++;
        }

        return ans;
    }
};
