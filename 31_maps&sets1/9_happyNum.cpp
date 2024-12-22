#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int digitSquareSum(int n){
        int sum = 0;
        while (n!=0){   // ha yaha not equal to zero tak hi chalana padega..
        /// ekdum usko tod tod ke zero kar dena h...
            int ld = n%10;
            sum += ld*ld;
            n = n/10; // for next iteration
        }
        return sum;
    }

    bool isHappy(int n){
       unordered_set <int> set;

       while (n!=1 && !set.count(n)){
           set.insert(n);
           n = digitSquareSum(n);   // for next iteration...
       }

        // is while loop se bahar aaye to do case either n == 1 => happ num => return true;
        // else set.count(n) =1 matlab element present mil gya hoga jo ki ab waha se loop start ho jaega...
        // otherwise saare hi unique aate they agar directly wo 1 as a sum de deta to...
        return (n==1);   
    }
};

// jab yaha mujhe uski frequency wagera store hi nahi karwani to hashmap kyu use karu... I just have to check
// whether the element is present or not which can be done using the unordered_set itself..
// set.count(n) -> returns boolean value whether n has been encountered in the set once or not....
