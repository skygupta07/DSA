// minimumPlatforms.cpp

// start time, end time, arrival , departure dekhte ke saath hi greedy sochna h...


/*

You are given the arrival times arr[] and departure times dep[] of all trains 
that arrive at a railway station on the same day. 

Your task is to determine the *minimum number of platforms* required at the station 
to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train 
and the departure of another. Therefore, when two trains arrive at the same time, 
or when one arrives before another departs, additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3

Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.



Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1

Explanation: All train times are mutually exclusive. So we need only one platform



Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3

Explanation: All 3 trains have to be there from 11:00 to 11:30



Constraints:
1≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359

Note: Time intervals are in the 24-hour format(HHMM), 
where the first two characters represent hour (between 00 to 23 ) and the last two characters 
represent minutes (this will be <= 59 and >= 0).

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train has to wait.
    int findPlatform(vector <int> &arr, vector <int> &dep) {
        int n = arr.size();

        // Create a vector of pairs to store arrival and departure times together
        vector <pair <int, int>> trains; // arrival, departure

        for (int i = 0; i < n; i++) {
            trains.push_back({arr[i], dep[i]});
        }

        // Sort the trains by their arrival times
        sort(trains.begin(), trains.end());

        // Min-heap to keep track of the earliest departure times among platforms in use
        priority_queue <int, vector<int>, greater<int>> minHeap; // stores departure

        // Iterate over each train
        for (int i = 0; i < n; i++){
            
            int arrival = trains[i].first; // current train arrival
            int departure = trains[i].second;

            // If the platform with the earliest departure is free before this train arrives,
            // then we can reuse that platform (remove the train that has already departed)
            
            if (!minHeap.empty() && minHeap.top() < arrival) {
                minHeap.pop(); // Free up the platform
            }

            // Allocate a platform for the current train by pushing its departure time
            minHeap.push(departure);
        }

        // The size of the min-heap gives the number of platforms used concurrently at max,
        // i.e., the minimum number of platforms required
        return minHeap.size();
    }
};



/*

Approach : let's think little practically here what we need is priority wise arranging  trains, 
such that we use least platforms.

say we have an intelligent  data structure whose size represents the total platforms 
and maintains a pointer to a train of  lowest departure time among present trains on all platforms.   

when new train comes (consider we have only one platform initially 
with only one train's departure data maintanded)

based on new train's arrival time we can 

compare the lowest daparture time of existing trains with the arrival time of this new train.

if there exists such train on platforms whose departure is less than arrival time of this new train,

then we will just add this new train to that platform and now data structure 
will maintain info of new train''s departure time and will remove the old train's data 
from that particular platform


if arrival time is greater than the existing train's lowest departure time time 
we will just add new platform for the train

 ( eventually platforms will dynamically change in the end the the required platforms  
  will be equal to the size of data structure ) 

 
we need priority queue which shows minimum element in the queue.

 

priority_queue<int, vector<int> , greater<int>> pq;

Solution :

store pair of arrival and departure into vector pair
sort vector pair as per the arrival time of trains

get min heap

if lowest departure time in existing platform queue is less
     than arrival time of new train then pop that train and add new train's departure time

else add new trains departure time to queue : assigning new platform to new train.
return size of platform queue.

*/


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    cin.ignore();

    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);

        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);

        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }

    return 0;

}

// } Driver Code Ends