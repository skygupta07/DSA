// largestNumber.cpp

/*

Given a list of non-negative integers nums, arrange them such that they form the largest number
and return it.

Since the result may be very large, so you need to return a string instead of an integer.


Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Comparator function to decide which combination forms a larger number
    //  (sorting in descending order) - i.e bada number yaha par pehle...

    // ascii value pe hi comparison hoga...
    
    /*
    // agar a+b > b+a, toh a ko pehle rakho
    // e.g. a = "9", b = "34" => "934" > "349", toh "9" ko pehle rakho
    */

    static bool cmp(const string &a, const string &b) {
        return (a + b) > (b + a);   // yeh condition mujhe kaafi fascinating lagi...
    }

    string largestNumber(vector <int> &nums) {
        // Convert each number to a string
        vector <string> strNums;

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
