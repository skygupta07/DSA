// kokoEatingBananas.cpp

/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas 
and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them 
instead and will not eat any more bananas during this hour.

Koko likes to eat sloly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4


Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30


Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 1e4
piles.length <= h <= 1e9
1 <= piles[i] <= 1e9

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Helper function to calculate the total hours needed to eat all bananas at a given speed
    long long getHoursToEatAll(vector <int> &piles, int bananasPerHour){
        // Variable to store total hours needed
        long long totalHours = 0; 

        for (int i = 0; i < piles.size(); i++){

            // Calculate hours to eat the current pile of bananas
            int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);   // double lagana is very important here
            
            totalHours += hoursToEatPile;  // Add the hours for the current pile to total hours
        }

        return totalHours;  // Return the total hours needed to eat all piles
    }

    // Function to find the minimum eating speed to finish all bananas within target hours
    int minEatingSpeed(vector<int>& piles, int targetHours){
        int lo = 1;
        int hi = *(max_element(piles.begin(), piles.end()));  // Set initial search range: 1 to the maximum pile size
        
        int ans = -1;  // Variable to store the result (minimum speed)


        while(lo <= hi) {

            int mid = lo + (hi - lo) / 2;  // Calculate the middle value of the current range
            
            // Get the total hours required to eat all bananas at speed 'mid'
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            // If the total hours are within the target, try to find a smaller speed
            if (hoursToEatAll <= targetHours) {
                ans = mid;  // Record the answer (this is the best speed found so far)
                hi = mid - 1;  // Move the hi pointer to try loer speeds
            }

            else {
                lo = mid + 1;  // If it exceeds the target hours, try a hier speed
            }

        }

        // Return the minimum eating speed found
        return ans; 
    }
};
