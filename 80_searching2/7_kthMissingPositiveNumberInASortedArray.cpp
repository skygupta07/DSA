#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        
        int expectedValue = 1;
        
        int missingValue = 0;
        int missingCount = 0;
        
        int idx = 0;
        
        while (idx < n && missingCount < k){
            if (arr[idx] == expectedValue){
                idx++;
                expectedValue++;
            }
            else{
                missingValue = expectedValue;
                expectedValue++;
                missingCount++;
            }
        }
        
        while (missingCount < k){
            missingValue = expectedValue;
            expectedValue++;
            missingCount++;
        }
        
        
        if (missingCount == k) return missingValue;
    }
};



class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int n = arr.size();
        int lo = 0;
        int hi = n-1;
        
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            
            int missingCount = arr[mid] - (mid + 1);
            
            if (missingCount < k) lo = mid + 1;
            else hi = mid - 1;
        }
        
        // the low pointer indicates the first position where the missing count reaches or exceeds k
        return k + lo;
    }
};




// leetcode


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0;
        int currentNum = 1;

        // Jab tak k missing elements nahi milte
        while (k > 0) {

            // Agar currentNum array mein hai → skip karo
            if (idx < arr.size() && arr[idx] == currentNum) {
                idx++; // move to next array element
            } 
            
            else {
                // currentNum is missing → count karo
                k--;
                if (k == 0) return currentNum; // agar yeh kth missing hai
            }
            currentNum++;
        }

        // Just in case (should not reach here)
        return -1;
    }
};




class Solution {
public:
    int findKthPositive(vector <int> &arr, int k) {
        unordered_set <int> availableNum;

        for (int i=0; i<arr.size(); i++) availableNum.insert(arr[i]);

        int expectedNum = 1;
        int missingNum = -1;

        while(true){

            if (availableNum.find(expectedNum) == availableNum.end()){
                missingNum = expectedNum;
                k--;
            }

            if (k == 0) return missingNum;

            expectedNum++;
        }

        return missingNum;
    }
};


// linear approach..
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lo = 0;
        int hi = arr.size() - 1;

        // Binary Search on index
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            int missing = arr[mid] - (mid + 1); // Kitne numbers ab tak missing hain

            if (missing < k) {
                lo = mid + 1;  // Missing abhi kam hain → right side jao
            } else {
                hi = mid - 1;  // Missing zyada hain → left side jao
            }
        }

        // lo is the count of numbers in array before kth missing number
        return lo + k;
    }
};
