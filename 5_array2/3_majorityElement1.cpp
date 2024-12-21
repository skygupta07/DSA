#include <bits/stdc++.h>
using namespace std;

class Solution { // Boyer-Moore Voting Algorithm
public:
    int majorityElement(vector<int>& arr) {
        int ele = arr[0]; // Initialize `ele` = majority element to the first element of the array

        int count = 0;    // Counter to track the frequency of the current candidate

        // Iterate through the array
        for (int i = 0; i < arr.size(); i++) {
            // If the counter is 0, update `ele` to the *current* element
            if (count == 0) ele = arr[i];
            
            // Update the count based on whether the current element matches `ele`
            if (ele == arr[i]) {
                count++; // Increase count if it matches the candidate
            } else {
                count--; // Decrease count if it does not match
            }
        }

        // Return the majority element
        return ele;
    }
};

/*

If there is a majority element (appearing more than n/2 times), it will remain as the final candidate because the decrements for other elements will never fully cancel out its dominance.


(jaake raako saaiya mar sake na koi...)
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        n = n/2;
        for(auto x: m){
            if(x.second > n){
                return x.first;
            }
        }
        return 0;
    }
};