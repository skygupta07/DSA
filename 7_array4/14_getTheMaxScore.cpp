#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        long long sum1 = 0;
        long long sum2 = 0;

        long long ans = 0;

        while (i < n1 && j < n2){
            if (nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j]){
                sum2 += nums2[j];
                j++;
            }
            else{   // both elements equal
                // khud ka plus pehle mai kisne max contribution diya hua hai...
                ans += nums1[i] + max(sum1, sum2);
                // ab dono index aage badhao
                i++;
                j++;

                // reset kara variable...
                sum1 = 0;
                sum2 = 0;
            }
        }

        // if array2 exhausted 
        while (i < n1){
            sum1 += nums1[i];
            i++;    // iske bina kuch while loop kam sa lagta hai...
        }

        while (j < n2){
            sum2 += nums2[j];
            j++;
        }

        ans += max(sum1, sum2);
        ans = ans%mod;
        return ans;
    }
};





/*
two pointer use kara ....
ek sum1 variable aur ek sum2 variable use kara..jab tak same element nahi milte unko sum1 , sum2 
mai add karte rahenge.... phir usi ko final answer mai add karenge jiska max contribution tha pehle ...

now agar inme se koi bhi ek array khatam hogayi to aage ke sum ke liye again sum1 aur sum2 ko 
zero kara .... and then dekha kiska max constribution hai sum mai...


*/