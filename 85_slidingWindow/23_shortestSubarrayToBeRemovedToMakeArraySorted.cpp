#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        int left = 0;
        while (left <= n-2 && arr[left] <= arr[left+1]) left++;

        if (left == n-1) return 0;

        int right = n -1;
        while (right > 0 && arr[right - 1] <= arr[right]){
            right--;
        }

        int mini = min(n-left-1, right);

        int i = 0;
        int j = right;

        while (i<=left && j<n){
            if (arr[i] <= arr[j]){
                mini = min(mini, j - i -1);
                i++;
            }
            else j++;
        }

        return mini;
    }
};