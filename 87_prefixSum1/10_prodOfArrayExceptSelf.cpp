// productOfArrayExceptSelf.cpp

#include <bits/stdc++.h>
using namespace std;

/*

Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

*/

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n);
       
        // vector ka tujhe bhaiya size initialise karna hi padega
        // prefix product array except self
        int p = nums[0];    // product variable...
        pre[0] = 1;     // default base case hota hai ki prefix[0] is one...

        for (int i=1; i<n; i++){
            pre[i] = p;
            p *= nums[i];
        }

        // suffix product array except self
        p = nums[n-1];  // p variable ko kyu cheda? => arey bhai to phir uska karna hi kya hai...
                        // redefine to same variable karoge nahi => directly ched do...
        
        // humne yaha chalaki kari hai ki ek hi vector mai abhi prefix product calculate kiya hi tha ki usi mai
        // ab suffix prod bhi multiply karne lage......

        // otherwise hum alag suffx array banate uske last wale element ko as a base default case 1 set karte and then 
        // aage ke elements nikalte...

        for (int i=n-2; i>=0; i--){
            pre[i] *= p;     //  thoda dhyan rakhne wali baat..
            p *= nums[i];
        }

        
        return pre;
    }
};

