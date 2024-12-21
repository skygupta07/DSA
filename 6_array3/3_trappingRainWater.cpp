#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        // constructing previous greatest element array
        int pge[n];
        pge[0] = -1;
        int mx = height[0];
        for (int i=1; i<n; i++){    // standard template for pge
            pge[i] = mx;    // pehle maano phir sach mai dekh ke update kar do...
            if (height[i]>mx) mx = height[i]; // prev ya next array banate hue mai condtion to
                                                // original height array se hi check hogi...
        }

        // constructing next greatest element array-> nge array to peeche se hi construct karte hai...
        int nge[n];
        nge[n-1] = -1;
        mx = height[n-1];   // reintialising the same mx variable again now this time for nge waka waka 
        for (int i=n-2; i>=0; i--){
            nge[i] = mx;
            if (height[i]>mx) mx = height[i];
        } 

        // constructing mini array -> iterating over both pge and nge ... whomsoever is lesser...comes in mini array
        int mini[n];
        for (int i=0; i<n; i++){
            if (pge[i] < nge[i]) mini[i] = pge[i];
            else mini[i] = nge[i]; // equal wala case bhi nge mai le liya....
        }

        // now check if height and mini condition then store water
        int water = 0;
        for (int i=0; i<n; i++){        // start ke and end ke -1 wale condition wale bach jayenge....
            if (height[i] < mini[i]) water += mini[i]-height[i];
        }
        return water;
    }
};

/*
create three array -> previous greatest element array and next greatest element array...
third array (c) as empty array and fill the smaller of pge and nge array's element ...

first aur last mai can't store water so put -1...

now check if height[i] < c[i] means water can be stored with amount c[i] - height[i]
where finding previous greatest element is just like finding max element of the array.....
bas yaha max ko pge mai fill bhi karte jaana hai...
pehle hum pge[i] mai element ko fill karenge then agar koi update ho rha hoga to wo karenge


*/