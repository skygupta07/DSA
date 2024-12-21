#include <bits/stdc++.h>
using namespace std;


int main(){

}


class Solution {
public:
    // Comparator function to decide which combination forms a larger number
    static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // Convert each number to a string
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Sort the string numbers using the custom comparator
        sort(strNums.begin(), strNums.end(), cmp);

        // Edge case: If the largest number is 0, return "0"
        if (strNums[0] == "0") {
            return "0";
        }

        // Concatenate the sorted numbers
        string result;
        for (string s : strNums) {
            result += s;
        }

        return result;
    }
};
