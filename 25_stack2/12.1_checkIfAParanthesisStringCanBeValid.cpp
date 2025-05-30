#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        // change the string by replacing unlocked string chars with '*'
        for (int i=0; i<n; i++){
            if (locked[i] == '0') s[i] = '*';
        }

        stack <int> open;
        stack <int> star;   // yes better is to store index...

        for (int i=0; i<n; i++){
            // if open bracket simply put its index in open stack
            if (s[i] == '(') open.push(i);
            else if (s[i] == '*') star.push(i);

            // if closing bracket then...
            else if (s[i] == ')'){
                // check first if open stack can help to make partner, then try with star.. agar dono ne hi haath khade kar diye to return false

                if (!open.empty()) open.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }

            // now string to traverse ho gayi, now check stack ka status...

            // if open stack have elements then make its parnter by help of star stack. (star will mimic like closing bracket)..(index constraint dekh ke but .. kyuki open should lie earlier then close)
        }
        while (!open.empty() && !star.empty() && (open.top() < star.top())){
                open.pop();
                star.pop(); 
        }

            // now check if star has elements left ? 
            // if star has odd elements left, then even star can't help himself...(1 to finally single hi reh jayega...)

        if (star.size() % 2) return false;

            // now here ideally open stack should be empty...

        return open.empty();
    }
};