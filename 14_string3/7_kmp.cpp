#include <bits/stdc++.h>
using namespace std;

// KMP (Knuth-Morris-Pratt) Algorithm ka prefix function (LPS array)
// Purpose: Har index pe longest proper prefix batata hai jo suffix bhi ho.
// Isse pattern matching fast hota hai without rechecking previous characters.

vector<int> kmp(string s) {
    // lps[i] will store length of the longest proper prefix which is also suffix for substring s[0...i]
    vector<int> lps(s.length(), 0); // initially sab 0

    // i = current index, start from 1 (kyunki lps[0] hamesha 0 hota hai)
    for (int i = 1; i < lps.size(); i++) {
        int prevIdx = lps[i - 1];  // pehle waale character ka lps value

        // Jab tak mismatch ho raha hai aur prevIdx > 0, peeche jao
        // Matched prefix ko chhota karte jao
        while (prevIdx > 0 && s[i] != s[prevIdx]) {
            prevIdx = lps[prevIdx - 1];
        }

        // Agar match mil gaya toh prefix length increase karo
        // s[i] == s[prevIdx] toh lps[i] = prevIdx + 1, nahi toh 0
        // NOTE: Brackets ka use zaruri hai warna ? : galat kaam karega
        lps[i] = (s[i] == s[prevIdx]) ? prevIdx + 1 : 0;
    }

    return lps; // final LPS array return karo
}
