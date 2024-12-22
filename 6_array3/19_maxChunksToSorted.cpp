#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Variables to track sums
        int i; 
        int co = 0; // yeh 'co' array ke elements ka cumulative sum store karega
        int sum1 = 0; // yeh 'sum1' indices ka cumulative sum store karega
        int ans = 0; // 'ans' chunks ki count rakhega

        // Har element par traverse karenge
        for (int i = 0; i < arr.size(); i++) {
            sum1 += i; // Indices ka sum increment karte hain
            co += arr[i]; // Array ke elements ka sum increment karte hain

            // Agar indices ka sum aur elements ka sum same hai, iska matlab yeh chunk sorted ban sakta hai
            if (sum1 == co) ans++;
        }

        // Total chunks ka count return karenge
        return ans;
    }
};
