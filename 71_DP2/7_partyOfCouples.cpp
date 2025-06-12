// partyOfCouples.cpp

/*

You are given an integer array arr[] of size n, representing n number of people in a party, 
each person is denoted by an integer. Couples are represented by the same number ie: 

two people have the same integer value, it means they are a couple. 

Find out the only single person in the party of couples.

Note: It is guarantee that there exist only one single person in the party.

Examples :

Input: arr[] = [1, 2, 3, 2, 1]
Output: 3
Explaination: Only the number 3 is single.


Input: arr[] = [1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6] 
Output: 4 
Explaination: 4 is the only single.
Input: arr[] = [1, 1, 3, 3, 2] 
Output: 2


Constraints:
1 ≤ arr.size() ≤ 10pow4
1 ≤ arr[i] ≤ 10pow6

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findSingle(int n, int arr[]){
        int freq[1000005] = {0};
        
        for (int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        
        for (int i=0; i<1000005; i++){
            if (freq[i] %2 == 1) return i;
        }

        return -1;
    }
};



/*
sabse sahi rahega ki array ki constraint dekh ke ussey 5 size bada ka frequency array bana liya..
t.c. = O(n)     s.c. = O(n)
*/

// -----------    ------------

class Solution{
    public:
    int findSingle(int n, int arr[]){
        int xorr = 0;

        for (int i=0; i<n; i++){
            xorr ^= arr[i];
        }

        return xorr;
        // t.c. = O(n) , s,c. = O(1)
    }
};

