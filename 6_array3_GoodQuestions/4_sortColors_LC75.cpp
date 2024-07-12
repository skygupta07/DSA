#include <iostream>
#include <vector>

using namespace std;
int main(){

}   

class Solution {
public:
    void sortColors(vector<int>& nums) {
    // sort the array of zero one and two
    
    int noz =0;
    int no1=0;
    int no2 = 0;


    for (int i=0; i<nums.size(); i++){
        if (nums[i]==0) noz++;
        else if (nums[i]==1) no1++;
        else no2++;

    }

    for (int i=0; i<noz; i++){
        nums[i]=0;
    }

    for (int i=noz; i<noz+no1; i++){    // this was good to update at the right index...
        nums[i]=1;

    }
    for (int i=noz+no1; i<noz+no1+no2; i++){
        nums[i]=2;
    }

    }
};

// two pointer algorithm (brute force)
