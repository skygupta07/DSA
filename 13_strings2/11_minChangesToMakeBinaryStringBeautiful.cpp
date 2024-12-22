#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minChanges(string s) {
        int n = s.length();

        int count = 0;

        int left = 0;
        int right = 1;

        while (right <= n-1){
            if (s[left] != s[right]){
                count++;
            }
            left += 2;
            right += 2;
        }

        return count;
    }
};