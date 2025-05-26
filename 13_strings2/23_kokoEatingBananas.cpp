#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to calculate the total hours needed to eat all bananas at a given speed
    long long getHoursToEatAll(vector<int>& piles, int bananasPerHour){
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
    int minEatingSpeed(vector<int>& piles, int targetHours)
    {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));  // Set initial search range: 1 to the maximum pile size
        int ans = -1;  // Variable to store the result (minimum speed)


        while(low <= high)
        {
            int mid = low + (high - low) / 2;  // Calculate the middle value of the current range
            
            // Get the total hours required to eat all bananas at speed 'mid'
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            // If the total hours are within the target, try to find a smaller speed
            if (hoursToEatAll <= targetHours)
            {
                ans = mid;  // Record the answer (this is the best speed found so far)
                high = mid - 1;  // Move the high pointer to try lower speeds
            }
            else
            {
                low = mid + 1;  // If it exceeds the target hours, try a higher speed
            }
        }
        //=================================================================
        return ans;  // Return the minimum eating speed found
    }
};
