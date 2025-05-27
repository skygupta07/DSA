// finding3DigitEvenNumbers.cpp


#include <bits/stdc++.h>
using namespace std;

/*

You are given an integer array digits, where each element is a digit. 
The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.

The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.


Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.


Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 


Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
 

Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9

*/

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector <int> freq(10, 0);
        vector <int> ans;

        for (int digit: digits) freq[digit]++;

        for (int num=100; num<=998; num+=2){
            int hundreds = num / 100;
            int tens = (num/10) % 10;
            int ones = num % 10;

            vector <int> digitFreq = freq;

            if (digitFreq[hundreds]-- > 0
            && digitFreq[tens]-- > 0 
            && digitFreq[ones]-- > 0){
                ans.push_back(num);
            }
        }

        return ans;
     }
};



class Solution {
public:

    vector<int> findEvenNumbers(vector<int>& arr){
        vector<int> ans;
        int n = arr.size();
        unordered_map <int, int> m;

        for (auto ele : arr){    // inserting array element into map...
            m[ele]++;
        }

        for (int i=100; i<999; i+=2){
            int x = i;  // to maintain the original ans...
            int a = x%10;   // ones place of that number
            x /= 10;

            int b = x%10;   // tens place of that num
            x /= 10;

            int c = x;      // hundreds place of that num..
            
            // now check karo set mai kya a, b ,c present hai...a ko check kiya and saath ke saath a ko 
            // set se remove bhi kiya....

            if (m.find(a) != m.end()){  // if a is present-> then erase a and check for b and c
                m[a]--;
                if (m[a]==0) m.erase(a);

                if (m.find(b) != m.end()){
                    m[b]--;
                    if (m[b]==0) m.erase(b);

                    if (m.find(c) != m.end()) ans.push_back(i);
                        m[b]++;
                }
                m[a]++;
            }
        }
        return ans; 
    }
};

 



// last pos par 0 2 4 6 8 if present then fix and make others combination for three digit number...
// then finally push only even no. into vector...

// compute all three digits even digits number and see if it could be formed from the digits in the array? 
/*
leading zero lagte hai aage and trailing zero lagte hai peeche....

m.find() -> keys hi find karta hai...


*/


class Solution {
public:

    bool canForm(unordered_map<int, int> mp, int n) {
        while (n > 0) {
            int ld = n % 10;

            if (mp.find(ld) == mp.end()) return false;
            mp[ld]--;

            if (mp[ld] == 0) mp.erase(ld);  

            n = n / 10;
        }

        return true;
    }

    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;
        for (auto el : digits) mp[el]++;

        vector<int> ans;

        for (int i = 100; i <= 998; i += 2) {  
            if (canForm(mp, i)) ans.push_back(i);
        }

        return ans;
    }
};