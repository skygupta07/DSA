#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // sabse bade container ka weight, jo minimum capacity hona chahiye
        int minWeight = *max_element(weights.begin(), weights.end());   // ==>> lo
        // total weight of saare containers
        int totalWeight = accumulate(weights.begin(), weights.end(), 0); // ==>> hi

        // jab tak minWeight ko totalWeight tak nahi le jaate
        while (minWeight < totalWeight) {
            // midWeight calculate karte hain, jo possible capacity ho sakti hai
            int midWeight = minWeight + (totalWeight - minWeight) / 2;

            // kitne din lag rahe hain package deliver karne mein
            int daysNeeded = 1;
            int currWeight = 0; // current day ka total weight

            // har package ko dekhte hain
            for (int weight : weights) {
                // agar current weight + current package ka weight midWeight se zyada ho gaya
                if (currWeight + weight > midWeight) {
                    daysNeeded++;   // ek naya din chahiye
                    currWeight = 0; // nayi day se start karte hain
                }

                currWeight += weight; // current weight ko update karte hain
            }

            // agar days ki requirement total days se zyada hai, toh minWeight ko increase karte hain
            if (daysNeeded > days) {
                minWeight = midWeight + 1;
            } else {
                totalWeight = midWeight;   // agar days ke andar ho sakta hai, toh capacity ko reduce karte hain
            }
        }

        // maxWeight return karte hain, jo minimum capacity hai
        return minWeight;
    }
};
