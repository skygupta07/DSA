class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin() , nums.end());    // nlogn
        // iss wale question mai ordering utni matter nahi kar rahi... yaha to hume count dekhna hai bus....

        // change nums to prefix 
        for (int i=1; i<n; i++){ // o(n)
            nums[i] += nums[i-1];
        }

        // now binary search in nums array the queries[i]
        vector <int> ans;

        for (int i=0; i<queries.size(); i++){
            int query = queries[i];

            int lo = 0;
            int hi = n-1;
            int best = 0;   // best trick to find the best index in case binary search mai perfect ekdum equal waala element na search kar rahe ho...

            while (lo <= hi){
                int mid = lo + (hi - lo)/2;

                if (nums[mid] <= query){
                   best = mid+1;
                   lo = mid + 1;
                }
                else hi = mid-1;
            }
            ans.push_back(best);
        }

        return ans;
    }
};


/*


accha ek cheej note kari aapne ki jab aap nums ko sort kar chuke ho ..and prefix array bhi aapka increasing sorted order mai hi hai...now prefix array mai lineraly kis extent tak jaa sakte hai na check karke hum binary search bhi to laga sakte hai...har query ke liye...

*/