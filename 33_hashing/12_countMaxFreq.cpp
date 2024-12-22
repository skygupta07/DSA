/*

You are given an array nums consisting of positive integers.
Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
The frequency of an element is the number of occurrences of that element in the array.

*/


class Solution {
public:
    int maxFrequencyElements(vector<int>& arr) {
        int freq[101] = {0};
        int maxF = 0;
        int f = 0;

        for (int x : arr){
            freq[x]++;

            f += (freq[x] == maxF);
            if (freq[x] > maxF){
                f = 1;
                maxF = freq[x];
            }
        }
        return f*maxF;
    }
};


// without extra space 

