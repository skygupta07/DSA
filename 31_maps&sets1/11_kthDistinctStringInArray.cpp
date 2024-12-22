#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        vector <string> unique;

        unordered_map <string, int> mp;

        for (auto el : arr){
            mp[el]++;
        }

        // map ne jaise marji store kar rakha ho ... koi nahi mai to acche se hi line wise dekhunga...

        for (const auto& str : arr) {
            if (mp[str] == 1) {
                unique.push_back(str);
            }
        }

        if (k > unique.size()) return "";
        return unique[k-1];
    }
};