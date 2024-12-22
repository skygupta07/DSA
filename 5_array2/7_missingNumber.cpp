#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0 se n tak saare element hone chahiye they but ek missing hai...
        // ek n+1 size ki array bana do usme philaal sabko false rakhna then 
        // har element par iterate karte hue ussey true kardo, jo bach gya wo missing

        int n = nums.size();
        vector <bool> check(n+1, false);
        // n+1 size ka vector banaya jisme ki har ek element ko bool value false assign kar di...

        for (int i=0; i<n; i++){
            int ele = nums[i];
            check[ele] = true;
        }

        for (int i=0; i<n+1; i++){ // iteration over vector named check
            if (check[i]==false) return i;  // yes that index is the missing number...
         }

        return -1;  
    }
};


// ------using hash set time-> O(n) and space- O(n) ----------

class Solution {
public:


    int missingNumber(vector<int>& nums){
        unordered_set <int> originalSet(nums.begin() , nums.end());

        int expectedNumCount = nums.size();

        for (int number = 0; number <= expectedNumCount; number++){
            if (originalSet.find(number) == originalSet.end()) return number;
        }
        return -1;
        
    }
};

/*
using hashset kara taki pick fast kare...

*/

// ----using xor operation time -> o(n)- and space -> O(1)  ----

class Solution {
public:
    int missingNumber(vector <int>& nums){
        int xorValue = nums.size();
        for (int i=0; i<nums.size(); i++){
            xorValue ^= i^nums[i];
        }
        return xorValue;
    }
};


// using xor operation
/*
xoring same value gives zero
i.e. if we are doing xor of n numbers the unique one without its pair will be caught up...

at the very beginning initialising xor value with arr.size()  and then xor 

*/



// using expectedSum - givenSum

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = ( n*(n+1)/2 );

        int givenSum = 0;
        for (int i=0; i<n; i++){
            givenSum += nums[i];
        }

        return expectedSum - givenSum;
        
    }
};









