#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Comparator to sort events by start time
    static bool cmp(vector <int> &a, vector <int> &b){
        return a[0] < b[0]; // sort on basis of start time
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        // Step 1: Sort events by start time
        sort(events.begin(), events.end(), cmp);

        int n = events.size();
        
        // Step 2: Build suffixMax array to store max values from the end of the array
        vector <int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2]; // Initialize with the value of the last event

        // Fill suffixMax array in reverse order
        for (int i=n-2; i>=0; i--){
            suffixMax[i] = max(events[i][2], suffixMax[i+1]);
        }

        int maxSum = 0; // Variable to track the maximum sum of two non-overlapping events

        // Step 3: Iterate through each event and find a non-overlapping event using binary search
        for (int i=0; i<n; i++){
            int lo = i+1; // Start binary search after the current event
            int hi = n-1;

            int nextEventIndex = -1; // To store index of the next non-overlapping event

            // Perform binary search to find the next non-overlapping event
            while (lo <= hi){
                int mid = lo + (hi - lo)/2;

                // Check if the start time of mid event is after the end time of current event
                if (events[mid][0] > events[i][1]){
                    nextEventIndex = mid; // Potential candidate
                    hi = mid - 1; // Narrow search range to the left
                }
                else lo = mid + 1; // Narrow search range to the right
            }

            // Step 4: Update maxSum if a valid pair is found
            if (nextEventIndex != -1){
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }

            // Also consider the case where only one event is chosen
            maxSum = max(maxSum, events[i][2]);
        }   
        return maxSum; // Step 5: Return the maximum sum
    }
};
