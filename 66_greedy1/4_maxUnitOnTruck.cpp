// maxUnitOnTruck.cpp

// https://leetcode.com/problems/maximum-units-on-a-truck/
#include <bits/stdc++.h>
using namespace std;


bool cmp(vector <int> &a, vector <int> &b){   // supports asc order
    return a[1] > b[1];
}

// vector of vector mai jo har koi vector hai usme bhi do element hai 
// har vector ka first element denotes number of boxes of type i
// and second -> numberOfUnitsPerBox

class Solution {    // important
public:
        // t.c. = O(nlogn)
    int maximumUnits(vector <vector<int>> &boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int profit = 0;
        
        for (int i=0; i<boxTypes.size(); i++){

            if(boxTypes[i][0] < truckSize){
                profit += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }

            else{
                profit += truckSize*boxTypes[i][1];
                truckSize = 0;
            }

            if (truckSize == 0) break;
        }

        return profit;
        
    }
};

/*

boxType array ko sort karenge on the basis of number of units per boxes

we will try to take all or max of boxes which contain more number or units per box

i.e. sorting a vector of vector but on the basis of certain property of any other moving variable 

=> custom comparator will be required.....

*/










int main(){

}


/*



*/
