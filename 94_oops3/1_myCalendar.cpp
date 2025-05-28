#include <bits/stdc++.h>
using namespace std;


/*

You are implementing a program to use as your calendar. 
We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection 
(i.e., some moment is common to both events.).

The event can be represented as a pair of integers startTime and endTime 
that represents a booking on the half-open interval [startTime, endTime), 
the range of real numbers x such that startTime <= x < endTime.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int startTime, int endTime) 
Returns true if the event can be added to the calendar successfully without causing a double booking. 
Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]


Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.

*/


class MyCalendar {
public:
    vector <pair <int, int>> ranges;
    
    MyCalendar() {}
    
    bool book(int start, int end){

        for (auto const &pair: ranges){
            int rangeStart = pair.first;
            int rangeEnd = pair.second;

            if (rangeEnd > start && rangeStart < end) return false;
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
    map <int, int> intervals; // Stores intervals with start as key and end as value

public:

    MyCalendar() {} // Constructor: No specific initialization needed

    bool book(int start, int end) {

         // Find the first interval with a start time greater than or equal to 'start'
        auto next = intervals.lower_bound(start);

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
