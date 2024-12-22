class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin() , nums.end());
        // create prefix sum array...

        int n = nums.size();
        int m = queries.size();

        vector <int> ans;

       
        // modifying the nums array to prefix array itself..
        for (int i=1; i<n; i++){
            nums[i] = nums[i] + nums[i-1]; 
        }

        // for each queries check at what extent you can go in prefix array...

        for (int i=0; i<m; i++){
            int target = queries[i];

            // iterating over each prefix array element ....
            int count = 0;
            for (int j=0; j<n; j++){
                if (nums[j] > target) break;
                else count++; 
            }
            // har query ka answer store kara...
            ans.push_back(count);
        }

        return ans;
    }
};




// -------- --- --  -

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin() , nums.end());
        // create prefix sum array...

        int n = nums.size();
        int m = queries.size();

        vector <int> ans;

        vector <int> pref(n, 0);
        pref[0] = nums[0];

        for (int i=1; i<n; i++){
            pref[i] = nums[i] + pref[i-1]; 
        }

        // for each queries check at what extent you can go in prefix array...

        for (int i=0; i<m; i++){
            int target = queries[i];

            // iterating over each prefix array element ....
            int count = 0;
            for (int j=0; j<n; j++){
                if (pref[j] <= target){ // jab tak range mai rahega mera count par khud par khud hi update hota rahega...... agar kahi bhi bada hogaya to uss query ke liye loop break kar jaega...
                    count = j + 1;
                }
                else break;
            }
            // har query ka answer store kara...
            ans.push_back(count);
        }

        return ans;
    }
};

// t.c. = O(mn)




----
class Solution { // t.c = O(mlogn)
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        sort(nums.begin() , nums.end());

        // change nums to prefix 
        for (int i=1; i<n; i++){
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