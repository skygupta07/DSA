class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;

        int lo = 0;
        int hi = nums.size() - 1;

        while (lo<=hi){
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] == target){
                if (nums[mid - 1] != target && mid-1 >=0){
                    start = mid; // storing index
                    break;
                }
                else{
                    hi = mid - 1;
                }
            }
            else if (nums[mid] < target) lo = mid+1;
            else hi = mid - 1;
        }

        // reset lo and hi again
        lo = 0;
        hi = nums.size() - 1;
        
        while (lo<=hi){
            int mid = lo + (hi - lo)/2;
            
            if (nums[mid] == target){
                if (nums[mid + 1] != target && mid+1 <= hi){
                    end = mid;
                    break;
                }
                else{
                    lo = mid + 1;
                }
            }
            else if (nums[mid] < target) lo = mid+1;
            else hi = mid - 1;
        }

        return {start,end};
    }
};


----------


/*

    Time Complexity : O(N), because in the worst case we traverse the <= N element. Where N is the size of the
    Array(nums).
                    
    Space Complexity : O(1), the space complexity is constant.

    Solved using Linear Search.

*/


/***************************************** Approach 1 First Code *****************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int startingPosition = -1, endingPosition = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                startingPosition = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};






/*

    Time Complexity : O(log N), since we have used binary search to find the target element. The time complexity
    is logarithmic.

    Space Complexity : O(1), since we stored only some constant number of elements, the space complexity is
    constant.

    Solved using Binary Search.

*/


/***************************************** Approach 2 First Code *****************************************/
