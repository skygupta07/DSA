#include <bits/stdc++.h>
using namespace std;

// Placeholder function for user to implement the logic
int GLPairs(int n, vector<int>& num) {
    unordered_map <int, int> mp;
    for (auto el : num) mp[el]++;

    int count = 0;
    for (auto el : mp){
        int freq = el.second;
        if (freq >= 2) count += (freq * (freq - 1))/2;
    }

    return count;
}

/*
it means both lcm and hcf should be equal..
i guess meaning both numbers should be equal then...
so number of pairs will be nc2   =  n * (n-1)/2
*/


