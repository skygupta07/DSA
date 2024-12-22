#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {    // t.c. = O(n) , s.c. = O(n)
        unordered_map <int, int> mp;

        for (auto el: target){
            mp[el]++;
        }

        for (auto el: arr){
            mp[el]--;
        }

        for (auto el: mp){
            if (el.second != 0){
                return false;
            }
        }
        return true;
    }
};



/*
creating map 
first iterate in arr1 and then increase freq of elements ..
    then iterate in arr2 and then decrease freq of elements...

    if in case now any element has frequency not equal to zero then return false...

    return true


*/



class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return (target == arr);
    }
};


/*

agar dono array mai same same element hai to phir to ho jaega 
    else not

*/