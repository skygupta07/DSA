#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for (int i=0; i<details.size(); i++){
            string detail = details[i];

            int tens = detail[11] - '0';
            int ones = detail[12] - '0';

            int age = tens*10 + ones;

            if (age > 60) count++;
        }

        return count;
    }
};n