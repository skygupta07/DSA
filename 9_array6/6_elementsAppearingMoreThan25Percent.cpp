// elementsAppearingMoreThan25Percent

/*

Given an integer array sorted in non-decreasing order, 
there is exactly one integer in the array that occurs more than 25% of the time, return that integer.


Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6


Example 2:

Input: arr = [1,1]
Output: 1

Constraints:

1 <= arr.length <= 1e4
0 <= arr[i] <= 1e5

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

        int findSpecialInteger(vector <int> &arr){
            int n = arr.size();
            
            // possibleAnswerIndex
            vector <int> possibleAnswer = {arr[n/4], arr[n/2], arr[3*n/4] , arr[n-1]}; 
    
            for (int i=0; i<4; i++){

                int lb = lower_bound(arr.begin(), arr.end(), possibleAnswer[i]) - arr.begin();
                int ub = upper_bound(arr.begin(), arr.end(), possibleAnswer[i]) - arr.begin();
            
                 if (ub - lb > n/4) return possibleAnswer[i];
            }
    
            return -1;
        }
    };
    
    
    /*
    
    lower_bound(start, end, value)
    Returns:
    
    An iterator pointing to the first position where value is found OR 
    the first element greater than value (if value is not present).
    If all elements are smaller than value, it returns end().
    
    
    vector <int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    auto it = lower_bound(arr.begin(), arr.end(), 2);
    cout << "Lower bound of 2 is at index: " << (it - arr.begin()); 
    
    Output:
    
    Lower bound of 2 is at index: 1
    
    
    upper_bound(start, end, value)

    Returns:
    
    An iterator pointing to the first position where an element is strictly greater than value.
    If no greater element is found, it returns end().
    
    
    vector<int> arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    auto it = upper_bound(arr.begin(), arr.end(), 2);

    cout << "Upper bound of 2 is at index: " << (it - arr.begin()); 
    Output:
    
    Upper bound of 2 is at index: 3

    */


    class Solution {
    public:
    
            int findSpecialInteger(vector<int>& arr) {
                int n = arr.size();
        
                unordered_map <int, int> freq;
        
                for (auto el : arr){
                    freq[el]++;
                    
                    // ye cheej mujhe sahi lagti h jaha computation karte waqt hi kucch conditional statement 
                    // daal do and apna kaam nikalwa lo...
                    if (freq[el] > n / 4) return el;
                }
        
                return -1;
            }
        };



        class Solution {
            public:
                int findSpecialInteger(vector<int>& arr) {
                    int n = arr.size();
            
                    unordered_map <int, int> freq;
            
                    for (auto el : arr) freq[el]++;
            
                    for (auto el : freq){
                        if (el.second > n / 4) return el.first;
                    }
            
                    return -1;
                }
            };