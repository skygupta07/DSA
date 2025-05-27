#include <bits/stdc++.h>
using namespace std;


/*

Given a data stream input of non-negative integers a1, a2, ..., an, 
summarize the numbers seen so far as a list of disjoint intervals.

Implement the SummaryRanges class:

SummaryRanges() Initializes the object with an empty stream.
void addNum(int value) Adds the integer value to the stream.
int[][] getIntervals() Returns a summary of the integers in the stream currently as a list 
of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 

Example 1:

Input
["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals", "addNum", 
"getIntervals", "addNum", "getIntervals", "addNum", "getIntervals"]
[[], [1], [], [3], [], [7], [], [2], [], [6], []]
Output
[null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]

Explanation
SummaryRanges summaryRanges = new SummaryRanges();
summaryRanges.addNum(1);      // arr = [1]
summaryRanges.getIntervals(); // return [[1, 1]]
summaryRanges.addNum(3);      // arr = [1, 3]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
summaryRanges.addNum(7);      // arr = [1, 3, 7]
summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 

Constraints:

0 <= value <= 104
At most 3 * 104 calls will be made to addNum and getIntervals.
At most 102 calls will be made to getIntervals.
 

Follow up: What if there are lots of merges and the number of disjoint intervals 
is small compared to the size of the data stream?

*/

class SummaryRanges {
    public:
        SummaryRanges() {
            // Constructor: Initializes an empty SummaryRanges object
        }
        
        void addNum(int value) {
            // Find the first interval where value could be inserted
            auto it = _map.lower_bound(value);
            bool merged = false;
    
            // Check if value can merge with the previous interval
            if (it != _map.begin()) {
                auto prev = it;
                --prev;
                if (prev->second + 1 >= value) { // Overlapping or adjacent intervals
                    merged = true;
                    prev->second = max(prev->second, value); // Extend the interval
                }
            }
    
            // Check if value can merge with the next interval
            if (it != _map.end()) {
                if (it->first - 1 <= value) { // Overlapping or adjacent
                    if (merged) { 
                        // If already merged with previous, merge with next as well
                        auto prev = it;
                        --prev;
                        if (prev->second >= it->first - 1) {
                            prev->second = max(prev->second, it->second);
                            _map.erase(it); // Remove merged interval
                        }
                    } else {
                        merged = true;
                        if (it->first != value) { // Adjust the interval start
                            pair<int, int> p = *it;
                            p.first = min(p.first, value);
                            it = _map.insert(it, p); // Insert the new adjusted interval
                            ++it;
                            if (it != _map.end())
                                _map.erase(it); // Remove duplicate intervals
                        }
                    }
                }
            }
    
            // If value was not merged, create a new interval
            if (!merged)
                _map.insert(it, {value, value});
        }
        
        vector<vector<int>> getIntervals() {
            // Convert the map to a list of intervals
            vector<vector<int>> intervals;
            for (auto const &p : _map)
                intervals.push_back({p.first, p.second});
            return intervals;
        }
    
    private:
        map<int, int> _map; // Stores intervals (start -> end)
    };
    