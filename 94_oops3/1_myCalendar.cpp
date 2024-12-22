#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    vector <pair <int, int> > ranges;
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto const &pair: ranges){
            int rangeStart = pair.first;
            int rangeEnd = pair.second;

            if (start < rangeEnd && end > rangeStart ) return false;
        } 
        ranges.push_back({start, end});  
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


class MyCalendar {
    map<int, int> intervals; // Stores intervals with start as key and end as value

public:
    MyCalendar() {} // Constructor: No specific initialization needed

    bool book(int start, int end) {
        auto next = intervals.lower_bound(start); // Find the first interval with a start time greater than or equal to 'start'

        // Check if the current interval overlaps with the next interval in the map
        if (next != intervals.end() && next->first < end) {
            return false; // Overlap with the next interval, so booking fails
        }

        // Check if the current interval overlaps with the previous interval in the map
        if (next != intervals.begin() && prev(next)->second > start) {
            return false; // Overlap with the previous interval, so booking fails
        }

        // No overlap detected, add the new interval to the map
        intervals[start] = end;
        return true; // Booking is successful
    }
};

/**
 * Your MyCalendar object will be instantiated and used as follows:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
