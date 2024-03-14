// //count distinct integers

// class Solution {
// public:
//     int reverse(int n){
//         int r = 0; // remainder =0 initially
//         while(n>0){
//             r = r*10;
//             r += n%10;  // adding last digit...
//             n = n/10;   // dividing the number by 10
//         }
//         return r;
//     }


//     int countDistinctIntegers(vector<int>& nums) {
     
//         unordered_set <int> s;
//         // trace over each element find its reverse and push back again into nums
//         // create a set and now insert nums element into it
//         // return the size of set

//         // or directly create a set and push all nums element and its reverse also 
            // (set property will handle no duplicacy) then return its size

//         for (int i=0; i<nums.size(); i++){
//             s.insert(nums[i]);
//             s.insert(reverse(nums[i]));
//         } 
//         return s.size(); 
//     }
// };