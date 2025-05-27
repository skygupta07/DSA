#include <bits/stdc++.h>
using namespace std;


/*
sorting ke behaviour ko decide karega..

swap (a[i] < a[j]) to ho hi raha tha....aap hi mention kar do aur kya karna hai...
jab mene khud se hi sorting ki O(n2) mai then mene custom comparator pass kiya...

inbuilt sorting algorithm ka custom comparator cheeze ulti leta hai....i.e. when you 
want the fn to do swapping then make the condition false...

simply wahi return kardo....jo tumhe chahiye....



*/


class Solution {
    public:
        // Comparator function should be static
        static bool cmp(vector<int> &a, vector<int> &b) {
            // har stage pe one bottle down karke hi cheeje sochi jaa rahi h...
            return a[0] < b[0];
        }
    
        vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
            unordered_map<int, int> mp;
    
            // Summing values instead of just counting occurrences
            for (auto el : nums1) mp[el[0]] += el[1];
            for (auto el : nums2) mp[el[0]] += el[1];
    
            vector <vector<int>> v;
    
            // Convert map to vector
            for (auto el: mp) {
                v.push_back({el.first, el.second});
            }
    
            // Sorting using static function
            sort(v.begin(), v.end(), cmp);
    
            return v;
        }
    };
    