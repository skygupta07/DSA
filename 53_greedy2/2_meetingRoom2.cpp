#include <bits/stdc++.h>
using namespace std;


class solution{
public:
    int minMeetingRooms(vector <vector <int> > &intervals){
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
        return ans;
    }

};





//Given an array of meeting time intervals consisting of start and end times 
//[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.)

/*
wo time interval jo ki overlapping hai wo to pakka ek meeting room mai nahi ho sakte...

starting aur ending time ko ascending order mai sort kara..
maintain i and j pointer
rooms aur ans variable maintain karte hue chalenge... at any time max of (rooms,ans)


if same time par meeting end and dusri start then use the same room
aur meeting ke starting time pe hi saara focus karna hai ...
jabtak starting array khatam nahi hoti....
*/