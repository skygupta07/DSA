#include <iostream>
using namespace std;
int main(){

}

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0; 
        int hi = nums.size()-1;
        int mid = 0;

        while (mid<=hi){
            if (nums[mid] == 2){
                 swap(nums[mid], nums[hi]);
                 hi--;
            }

            else if(nums[mid] == 0){
                swap(nums[mid], nums[lo]);
                lo++;
                mid++;
            }

            else{ // nums[mid]==1
                mid++;
            }

           
        }
        return;
        
    }
};

/*
dutch flag algo use (one pass algo) three pointer method
lo mid hi    hamesha mid ke baare me socho
initially lo aur mid ko zero pe rakho and hi ko last mai...
if nums[mid] == 2 then swap with hi
if (nums[mid] ==0) swap mid with lo
if (nums[mid] == 1) mid++;
*/


/*
3 pointer algorithm or dutch flag algorithm...

mid ke saath khelenge
kabhi bhi mid aapka low se to peeche nahi hona chahiye...
maintain the order such that low se pehle sab kuchh smallere(i.e 0 her) ... 
high ke baad bade wale like 2 and beech mai middle (i.e. 1 here)




*/