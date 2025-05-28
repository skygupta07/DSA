// mergeIntervals.cpp - imp to learn steps - OA frequently asked

/*

Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.


Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

#include <bits/stdc++.h>
using namespace std;

// Interval ko unke end time ke basis pe sort karne ke liye custom comparator
bool cmp(vector <int> &a, vector <int> &b){
    return a[1] < b[1]; // Agar a ka end time chhota hai b ke end time se, toh a pehle aayega
}

class Solution {
public:

    vector<vector<int>> merge(vector <vector<int>> &intervals){
        // Step 1: Intervals ko unke end time ke basis pe sort karo
        sort(intervals.begin(), intervals.end(), cmp);

        vector <vector <int>> result; // Yeh final merged intervals store karega

        int n = intervals.size();
        if (n == 1) return intervals; // Agar sirf ek interval hai toh wahi return kar do

        // Step 2: Sabse last interval ko result mein daal diya, kyuki hum ulta loop chalayenge
        result.push_back(intervals[n - 1]);

        // Step 3: Baaki intervals pe ulta loop chala rahe hain (right se left)
        for (int i = n - 2; i >= 0; i--) {

            // Curr variable current interval ko store kar raha hai
            vector <int> curr = intervals[i];

            // Agar current interval ka end time, result ke last wale interval ke start time se bada ya barabar hai
            if (curr[1] >= result[result.size() - 1][0]) {
                // Overlap ho raha hai, isliye merge kar do

                // start time ka minimum aur end time ka maximum leke update kar do
                result[result.size() - 1][0] = min(result[result.size() - 1][0], curr[0]);
                result[result.size() - 1][1] = max(result[result.size() - 1][1], curr[1]);
            }

            // Overlap nahi ho raha, toh yeh interval alag hai, isko result mein daal do aise hi
            else result.push_back(intervals[i]);
            
        }

        // Kyuki humne ulta loop chala ke result banaya hai, ab usko reverse kar do
        reverse(result.begin(), result.end());

        return result; // Final merged intervals return kar do
    }
};





























int main(){

}  


/*







*/