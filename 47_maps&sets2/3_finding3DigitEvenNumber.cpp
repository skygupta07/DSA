/*

class Solution {
public:

    vector<int> findEvenNumbers(vector<int>& arr){
        vector<int> ans;
        int n = arr.size();
        unordered_map <int, int> m;
        for (auto ele : arr){    // inserting array element into map...
            m[ele]++;
        }

        for (int i=100; i<999; i+=2){
            int x = i;  // to maintain the original ans...
            int a = x%10;   // ones place of that number
            x /= 10;
            int b = x%10;
            x /= 10;
            int c = x;
            
            // now check karo set mai kya a, b ,c present hai...a ko check kiya and saath ke saath a ko 
            // set se remove bhi kiya....

            if (m.find(a) != m.end()){  // if a is present-> then erase a and check for b and c
                m[a]--;
                if (m[a]==0) m.erase(a);
                if (m.find(b) != m.end()){
                    m[b]--;
                    if (m[b]==0) m.erase(b);
                    if (m.find(c) != m.end()) ans.push_back(i);
                        m[b]++;
                }
                    m[a]++;
                }
            }
         
    return ans; 
    }
};

 
 */




// last pos par 0 2 4 6 8 if present then fix and make others combination for three digit number...
// then finally push only even no. into vector...

// compute all three digits even digits number and see if it could be formed from the digits in the array? 
/*
leading zero lagte hai aage and trailing zero lagte hai peeche....

m.find() -> keys hi find karta hai...



*/