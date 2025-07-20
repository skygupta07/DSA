// maximumSumSubarrayOfSizeK.cpp


/*

Given an array of integers arr[]  and a number k. 
Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.


Examples:

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.


Input: arr[] = [100, 200, 300, 400] , k = 4
Output: 1000
Explanation: arr1 + arr2 + arr3 + arr4 = 1000, which is maximum.


Input: arr[] = [100, 200, 300, 400] , k = 1
Output: 400
Explanation: arr4 = 400, which is maximum.


Constraints:
1 <= arr.size() <= 1e6
1 <= arr[i]<= 1e6
1 <= k<= arr.size()


*/


// brute force -> gave tle
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0;
        int right = k-1;
        
        int maxSum = 0;
        
        while (right < n){
            // as accumulate(start, end) is exclusive of the end pointer
            int currSum = accumulate(arr.begin()+left, arr.begin()+right+1, 0);
            
            
            maxSum = max(maxSum, currSum);
            
            left++;
            right++;
        }
        
        
        return maxSum;
    }
};




class Solution {
public:

    int maximumSumSubarray(vector <int> &arr, int k) {
        int n = arr.size();
        
        int windowSum = 0;
        for (int i=0; i<k; i++) windowSum += arr[i];
        
        int maxSum = windowSum;
        
        for (int i=k; i<n; i++){
            windowSum = windowSum - arr[i-k] + arr[i];
            
            maxSum = max(maxSum, windowSum);
        }
        
        return maxSum;
        
    }
};


#include <bits/stdc++.h>
using namespace std;


int main(){

    int arr[] = {2,4,7,8,10,1,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 3;

    int maxSum = INT_MIN;
    int maxIdx = -1;

    // i batata hai ki window kaha se leke kaha tak jaa sakti hai...i.e.
    // uska starting point kya hai...

    for (int i=0; i<=n-k; i++){  // O(n-k)
        int windowSum = 0;

        for (int j=i; j<=i+k-1; j++){  // window size controller (k times)
            windowSum += arr[j];
        }

        // update windowSum and maxIdx
        if (windowSum > maxSum){
            maxSum = windowSum;
            maxIdx = i;
        }

    }

    // total = O(n-k+1)*k
    cout<<"max sum subArray of size k is: "<<maxSum<<endl;

    // printing which window element added this max sum..
    for (int p=maxIdx; p<(maxIdx+k); p++){
        cout<<arr[p]<<" ";
    }

    cout<<endl;

}    


/*

better rehta hai... i <= n-1 , wali condition...

->i pointer telling ki mera window kaha se lekar kaha tak jaa sakta hai..
-> j controlling search area to be of window length
-> current window ke khatam hote hi aur nayi window search karne ke se pehle apne 
maxsum ko update kar do

but iss brute force mai humne sabka sum dubara dubara nikala jabki unme se KAAFI elements
next window mai common they

-> so use sliding window...

*/