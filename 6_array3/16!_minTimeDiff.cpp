// minimumTimeDifference.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given a list of 24-hour clock time points in "HH:MM" format, 
return the minimum minutes difference between any two time-points in the list.

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1

Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 
Constraints:

2 <= timePoints.length <= 2 * 1e4
timePoints[i] is in the format "HH:MM".

*/

class Solution {
public:

    // Custom comparator function for sorting time points
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        // Agar hour same hai toh minutes ka comparison karo
        if (a.first == b.first) {
            return a.second < b.second;
        }
        // Nahi toh hour ke basis pe sort karo
        return a.first < b.first;
    }

    int findMinDifference(vector<string>& timePoints) {
        // Time points ko (hour, minutes) pair mein convert karne ke liye vector
        vector<pair<int, int>> time;

        // Step 1: Convert "HH:MM" string to (hour, minute) integer pairs
        for (auto str : timePoints) {
            // str[0] aur str[1] se hour banaya (e.g. "23" -> 2 * 10 + 3 = 23)
            int hour = (str[0] - '0') * 10 + (str[1] - '0');
            // str[3] aur str[4] se minutes banaya (e.g. "45" -> 4 * 10 + 5 = 45)
            int mins = (str[3] - '0') * 10 + (str[4] - '0');
            // hour aur mins ko ek pair bana ke store kar diya
            time.push_back({hour, mins});
        }

        // Step 2: Sort time points using the custom comparator
        sort(time.begin(), time.end(), cmp);

        // Step 3: Initialize minimum difference as max possible i.e., 24*60 = 1440 mins
        int mini = 1440;

        // prevHour and prevMins will keep track of previous time point
        int prevHour = time[0].first;
        int prevMins = time[0].second;

        // Store first time point separately for circular comparison later
        int firstHour = time[0].first;
        int firstMins = time[0].second;

        // Step 4: Loop over sorted time points to compute adjacent differences
        for (int i = 1; i < time.size(); i++) {
            int currHour = time[i].first;
            int currMins = time[i].second;

            // Calculate time difference in minutes between current and previous time point
            int timeDiff = (currHour - prevHour) * 60 + (currMins - prevMins);

            // Update minimum difference
            mini = min(mini, timeDiff);

            // Move previous pointer forward
            prevHour = currHour;
            prevMins = currMins;
        }

        // Step 5: Handle circular edge case (e.g. 23:59 and 00:01)
        // Wrap around from last time point to first time point

        /*
            Formula Explanation:
            Total minutes from prevHour to midnight = (24 - prevHour) * 60 - prevMins
            Add minutes from midnight to firstHour and firstMins = (firstHour * 60 + firstMins)
            Final = (24 - prevHour) * 60 - prevMins + firstHour * 60 + firstMins
                  = (24 - prevHour + firstHour) * 60 + (firstMins - prevMins)
        */

        int circularDiff = (24 - prevHour + firstHour) * 60 + (firstMins - prevMins);

        // Update minimum again
        mini = min(mini, circularDiff);

        // Step 6: Return final minimum difference in minutes
        return mini;
    }
};

