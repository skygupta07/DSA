#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Event {
private:
    int start;
    int end;

public:
    // Constructor
    Event(int start, int end) : start(start), end(end) {}

    // Getter methods for accessing private members
    int getStart() const { return start; }
    int getEnd() const { return end; }
};

class MyCalendarTwo {
private:
    vector<Event> bookings;
    vector<Event> overLapBookings;

    // Private helper function to check for overlap
    bool isOverlap(const Event& e, int start, int end) const {
        return max(e.getStart(), start) < min(e.getEnd(), end);
    }

    // Private helper function to create an overlap event
    Event getOverlapEvent(const Event& e, int start, int end) const {
        return Event(max(e.getStart(), start), min(e.getEnd(), end));
    }

public:
    // Constructor
    MyCalendarTwo() = default;

    // Public method to book an event
    bool book(int start, int end) {
        for (const Event& e : overLapBookings) {
            if (isOverlap(e, start, end)) {
                return false;
            }
        }

        for (const Event& e : bookings) {
            if (isOverlap(e, start, end)) {
                overLapBookings.push_back(getOverlapEvent(e, start, end));
            }
        }

        bookings.push_back(Event(start, end));
        return true;
    }
};
