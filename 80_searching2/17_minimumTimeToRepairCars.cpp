// minimumTimeToRepairCars.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            // Initialize the binary search range
            long long lo = 0;           // Minimum possible time
            long long hi = 1e14;        // A large upper bound for the maximum time required
    
            // Perform binary search on the minimum possible time
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;  // Calculate the mid-point (candidate time - ha yaha par time ko mid wala mohra banaya...)
                long long repairedCars = 0;         // Count of cars that can be repaired within 'mid' time
    
                // Calculate the total number of cars that can be repaired in 'mid' time
                for (int &r : ranks) {
                    repairedCars += sqrt(mid / r);  // Each mechanic repairs cars based on sqrt(mid / rank)
                }
    
                // If fewer than 'cars' are repaired, increase the time limit
                if (repairedCars < cars) lo = mid + 1;
                else hi = mid; // Otherwise, reduce the time limit
            }
            
            return lo;  // The minimum time required to repair 'cars' cars
        }
    };
    