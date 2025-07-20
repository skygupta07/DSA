/*

🧾 Problem: Maximum Sum Subarray of Size K (with Subarray Output)
You are given an integer array arr[] of size n, and an integer k, 
which represents the size of a sliding window.

Your task is to:

Find the maximum sum among all contiguous subarrays of size k.

Print the maximum sum, and
Print the elements of the subarray which gives this maximum sum.


🧿 Input:
An array of integers:
arr[] = {1, 3, 5, 7, 9, 10, 2, 10}

An integer:
k = 4

✅ Output:
Maximum window sum: 31
Subarray with maximum sum: 7 9 10 5


🔍 Constraints:
1 <= k <= n <= 10^6
-10^4 <= arr[i] <= 10^4


🧠 Example Explanation:
For input arr = [1, 3, 5, 7, 9, 10, 2, 10] and k = 4,
All windows of size 4 and their sums:

[1, 3, 5, 7] → 16
[3, 5, 7, 9] → 24
[5, 7, 9, 10] → 31 ✅
[7, 9, 10, 2] → 28
[9, 10, 2, 10] → 31 ✅
Two subarrays have the same max sum of 31, but the code returns the first occurrence.

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,3,5,7,9,10,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int k = 4; // window size

    int maxSum = INT_MIN;

    int maxIdx = -1;
    int prevSum = 0;

    // sabse pehli baar to khidki bharni hi padegi
    for (int i=0; i<k; i++){    
        prevSum += arr[i];
    }

    maxSum = prevSum;


    // left, right pointer ya i , j pointer use karte h window track karne ke liye

    int i = 1; //imp -> i pointer denotes start of window
    int j = k; // imp -> j pointer denotes end of window

    // constraint right waale hi pointer pe hai..
    while (j<n){  

        // currentWindowSum = prevWindowSum + lastElement of current window - first element of prev window

        int currSum = prevSum + arr[j] - arr[i-1]; // calculating current window sum
        
        // now check and update if maxSum has been changed
        if (currSum > maxSum){
            maxSum = currSum;
            maxIdx = i; // remembering the starting index of maxSum sliding window...
        }
        
         // next window banane se pehle ke updates - important
        prevSum = currSum; 

        i++;    // both i and j pointer will be incremented by 1, to move window ahead
        j++; 
    }

    cout<<"max window sum is: "<<maxSum<<endl;

    for (int p=maxIdx; p<(maxIdx+k); p++){
        cout<<arr[p]<<" ";
    }
    cout<<endl;
}







/*
1 2 3 4 5 6 7 8 9 

1 2 3 = 6
2 3 4 = 9  =(2+3) + 4
3 4 5 = 13 = (3+4) + 5

currSum = prevSum + currNext - prevFirst

-> window starting from i pointer 

*/