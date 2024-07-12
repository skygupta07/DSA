// lc 42
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height){
        int n = height.size();
        // constructing previous greatest element array
        int prev[n];
        prev[0] = -1;
        int max = height[0];
        for (int i=1; i<n; i++){
            prev[i] = max;
            if (height[i]>max) max = height[i]; // prev ya next array banate hue mai condtion to
                                                // original height array se hi check hogi...
        }

        // constructing next greatest element array
        int next[n];
        next[n-1] = -1;
        max = height[n-1];
        for (int i=n-2; i>=0; i--){
            next[i] = max;
            if (height[i]>max) max = height[i];
        } 

        // constructing mini array
        int mini[n];
        for (int i=0; i<n; i++){
            if (prev[i]<next[i]) mini[i] = prev[i];
            else mini[i] = next[i];
        }

        // now check if height and mini condition and store water
        int water = 0;
        for (int i=0; i<n; i++){
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









int main(){

}