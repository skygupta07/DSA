#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {    // if same hour then compare on the basis of minutes
            return a.second < b.second;
        }
        return a.first < b.first;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> time;

        for (auto str : timePoints) {
            int hour = (str[0] - '0') * 10 + (str[1] - '0');    // char ko integer mai karne ke liye sach mai integer minus kiya...
            int mins = (str[3] - '0') * 10 + (str[4] - '0');
            time.push_back({hour, mins});
        }

        sort(time.begin(), time.end(), cmp);

        int mini = 1440; // max possible time gap in minutes (24 * 60)

        int prevHour = time[0].first;
        int prevMins = time[0].second;

        // Handle circular difference (between last and first time)
        int firstHour = time[0].first;
        int firstMins = time[0].second;

        for (int i = 1; i < time.size(); i++) {
            int currHour = time[i].first;
            int currMins = time[i].second;

            int timeDiff = (currHour - prevHour) * 60 + (currMins - prevMins);
            mini = min(mini, timeDiff);

            prevHour = currHour;
            prevMins = currMins;
        }

        // Calculate the circular difference (wrap-around at midnight)
        int circularDiff = (24 - prevHour + firstHour) * 60 + (firstMins - prevMins);
        mini = min(mini, circularDiff);

        return mini;
    }
};
