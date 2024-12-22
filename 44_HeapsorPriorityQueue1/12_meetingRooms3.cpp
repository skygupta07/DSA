#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

*/




# define ll long long int

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        map <int, int> booked;

        // sort by smallest end time..
        auto compare = []( const pair <ll, int> &a, const pair <ll, int> &b ){
            if ( a.first == a.second ) return a.second > b.second;
            else return a.first > b.first;
        };


        // maintain data structure priority_queue for currently occupied rooms...


                    //.  end time , room id
        priority_queue < pair <ll, int> , vector <pair <ll, int>>, decltype(compare) > pq;
        priority_queue <int , vector <int> , greater <int>> freeRooms;

        for (int i=0; i<n; i++) freeRooms.push(i);

        sort (meetings.begin() , meetings.end());
        for (auto &v : meetings){
            ll start = v[0] , end = v[1];   // start and end time of current meeting..
            // if any existing occupied meeting room can be freed up before starting this current meeting...

            while (!pq.empty() && pq.top().first <= start){
                freeRooms.push(pq.top().second);
                pq.pop();
            }

            // if free rooms are available then choose smallest id free room...
            if (!freeRooms.empty()){
                booked[freeRooms.top()]++;
                pq.push( { end, freeRooms.top() } );
                freeRooms.pop();
            }
            // if free room not available then choose smallest end time room from occupied...
            else{
                booked[pq.top().second]++;
                auto p = pq.top();
                pq.pop();

                        // end time + diff,   Room id....
                pq.push( {p.first + end - start  , p.second } );
            }
        }

        int maxRooms = 0;
        int meetingRoom = -1;

        for (auto p: booked){
            if (p.second > maxRooms){
                maxRooms = p.second;
                meetingRoom = p.first;
            }
        }
        return meetingRoom;
    }
};


/*
google->20 times last 6 month

// meeting delay karwa do theek hai... but time to pura utna hi lenge guru....


sort the meetings on basis of start time
keep track of free rooms also...and at a time you need to give the smallest free room

before asking for new unused room I should check if anyone of older room has been emptied or not..
agar koi meeting delay bhi ho rahi hai to ussey baad mai hi sahi room to allot karna hi hai...

ek min end time bhi dekhna hoga..
delayed meetings ka time change ho raha hai depending on when they got free rooms....

custom comparator mai priority queue ke case mai
return a.second > b.second  // smaller will come in beginnig...


pq.top() -> smallest occupied room

map <int, int> booked   -> roomid as key    and number of rooms alloted as value..

*/

// -----method-2 ------


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        vector< long long > times(n,0);
        sort(meetings.begin(),meetings.end());

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0], end = meetings[i][1];
            bool flag = false;
            int minind = -1;
            long long val = 1e18;
            for(int j=0;j<n;j++){
                if(times[j]<val) val = times[j], minind = j;
                if(times[j] <= start){
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if(!flag){
                ans[minind]++;
                times[minind]+=(1ll*(end-start));
            }
        }
        int maxi = -1, id = -1;
        for(int i =0;i<n;i++){
            if(ans[i]>maxi) maxi = ans[i], id = i;
        }
        return id;
    }
};



