#include <bits/stdc++.h>
using namespace std;


class solution{
public:
    bool canAttendMeetings(vector<Interval> &intervals){
        if (intervals.size()==0) return true;
        vector <int> start;
        vector <int> ending;
        for (auto el: intervals){
            start.push_back(el[0]);
            ending.push_back(el[1]);
        }
        sort(start.begin(), start.end());
        sort(ending.begin(),ending.end());

        int ans = 0;
        int rooms = 0;
        int i=0, j=0;   // i and j iterates over start and ending array respectively..
        while (i<start.size() and j<ending.size()){
            if (start[i]<ending[j]){
                // a new meeting has started
                rooms++;
                ans = max(rooms, ans);
                i++;
            }
            else if (start[i] > ending[j]){
                // a meeting is ending -> chalo chalo usi room mai...
                rooms--;
                j++;    
            }
            else{
                i++;
                j++;
            }
        }
        if (ans ==1) return true;
        else return false;
    }

};


/*
if only one meeting room is required for the whole time interval means that no 
meeting was overlapping and hence the person can attend all the meeting one after another
in the same room itself...

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei
), determine if a person could attend all meetings.

*/

