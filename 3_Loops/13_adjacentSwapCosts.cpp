#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int i =0;
        int j = s.length()-1;

        while (i<j){
            if (s[i] == '1' && s[j] == '0'){
                swap(s[i], s[j]);
                steps += j-i;   // adjacent swap costs...
                i++;
                j--;
            }
            else if (s[i] == '1' && s[j]=='1'){
                j--;
            }
            else if (s[i] =='0' && s[j] == '1'){
                i++;
            }
            else if (s[i] =='0' && s[j] == '0'){
                i++;
            }
        }

        return steps;
    }
};


// 0011 format -> min swaps 