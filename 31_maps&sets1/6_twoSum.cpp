#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();

        // bahar wala loop zero se last-1 index tak and andar wala loop 1 se last index tak 
        // issey saare pairs generate ho jaate hai...
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if (nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    
                }
            }
        }
        return ans;
        
    }
};


// -------

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target){
        int n = v.size();
        unordered_map <int, int> mp;    // key,value = element,index store...

        for (int i=0; i<n; i++){
            int compEle = target - v[i];

            if (mp.find(compEle) != mp.end()){
                return {i , mp[compEle]};
            }

            // pehle question se hi iss type ke pattern se familiar hu mai..
            // if compEle not found then push <currElement, its index > into the map
            mp[v[i]] = i; 
        } 
        return {};
    }
    
};



/*
hash map bana and find at each stage complement(or what you require to form the pair actually...) 


*/