#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector <int> &flowerbed, int n) {
        // Agar n == 0 hai, iska matlab kuch bhi flower nahi lagana, toh directly true return kar do
        if (n == 0) {
            return true;
        }
        
        // Flowerbed ko traverse karna start karte hain
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check karte hain agar current spot pe flower lagana possible hai
            // 1. flowerbed[i] == 0 hona chahiye (current spot khaali hai)
            // 2. ya toh yeh first spot hona chahiye ya phir just iske pehla wala spot bhi khaali hona chahiye
            // 3. ya toh yeh last spot hona chahiye ya iska agla spot bhi khaali hona chahiye
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i-1] == 0) && 
                (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                
                // Agar yeh conditions satisfy hoti hain, toh yaha flower laga dete hain
                flowerbed[i] = 1;
                n--; // Ek flower lag gaya, toh n ko reduce kar dete hain
                
                // Agar saare flowers lag chuke hain (n == 0), toh true return kar do
                if (n == 0) {
                    return true;
                }
            }
        }
        
        // Agar poora flowerbed traverse kar liya aur phir bhi flowers nahi laga paaye, toh false return karo
        return false;
    }
    
};


/*

mai bas ye i == 0 
aur i == flowerbed.size() - 1    pe very starting and very ending wala case nahi soch paa rha tha.
*/
