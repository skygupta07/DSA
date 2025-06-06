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