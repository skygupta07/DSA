/*

class Solution {
public:
    int rev(int n){
        int r = 0;
        while (n>0){
            r*= 10;
            r += n%10;
            n = n/10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums){
        int n = nums.size();
        int count = 0;
        unordered_map <int,int> m;

        for (int i=0; i<n; i++){
            nums[i]-= rev(nums[i]); // modifying array...
        }

        // now finding if the number exist again in map...
        for (int i=0; i<n; i++){
            if (m.find(nums[i]) != m.end()){
                count = count%1000000007;   // pehle count ko modify karlo 
                count += m[nums[i]];    // existing frequency ko add kardo..
                m[nums[i]]++;   // then ek frequency badha do..
            }
            else m[nums[i]]++; // agar wo element nahi bhi milta to kya atleast map mai to daalunga na uss 
                                    // element ko....
        }
        return count%1000000007;    // and finally ek baar aur theek karke return kar do...
    }
};

*/