/*
class Solution {
public:
    vector <int> dp;   // competitive coders declare dp globally else fn me har 
                        // jagah pass karna padta...
                        
    // int f(vector<int> arr, int i){
    //     int n = arr.size();
    //     if (i == n-1) return arr[n-1];
    //     if (i == n-2) return max(arr[i], arr[i+1]);
    //     int loot = arr[i] + f(arr, i+2);
    //     int notLoot = 0 + f(arr, i+1);
        
    //     return max(loot, notLoot);
    // }


    // int ftd(vector<int> arr, int i){   // ftd means fn top down  
    //     int n = arr.size();
    //     if (i == n-1) return arr[n-1];
    //     if (i == n-2) return max(arr[i], arr[i+1]);

    //     // base case ke baad seedhe dp ki help le sakte ho to le lo..
    //     if (dp[i]!= -1) return dp[i];
    //     // agar dp nahi banai to banao na!!

    //     int lootPath = arr[i] + ftd(arr, i+2);
    //     int notLootPath = 0 + ftd(arr, i+1);


    int fbu(vector<int> arr){
        int n = arr.size();
        if (n==1) return arr[0];

        dp.clear();
        dp.resize(n);
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1], arr[n-2]);
        for (int i=n-3; i>=0; i--){
            dp[i] = max(arr[i] + dp[i+2] , 0 + dp[i+1]);
        }

        return dp[0];  // peeche se trace karte hue aata hue zeroth index me hi ans aa jaega

    }
        
    //     return dp[i] = max(lootPath, notLootPath);
    // }
    

    int rob(vector<int>& nums){
        dp.clear();         // main fn me jo bhi dp hai use clear karo
        dp.resize(100);      // then usko resize karo constraint + 5 size se

        return fbu(nums);   // fn call lagao 
    }

};


/*
brute force
taking those subsets only where no adjacent elements taken

// recursive fn mai array ke saath index bhi pass karna hota hai...

// f(arr,i) -> this recursive function returns max profit by looting houses from index 
'i' to n-1  (last house) such that no two adjacent houses are looted

last ke base cases isliye handle ho rahe hai kyuki kisi bhi nayi ith state ko as a fresh state treat kar rahe hai 
and waha se recursive fn kaam karega acche se 

main fn se hum f(arr, 0) 0th index pass kar rahe hai because hume starting from first house saare include karne hai...
-> state of the dp can be identified by the single variable index i

optimal substructure bhi hai yaha because choti subproblem ko combined use  karke badi problem ka solution 
ban rahi hai...

vector <int> dp maine globally banayi now leetcode alag alag testcases ke liye check karta hai...
jisme ki purane waale testcase ka garbage value store ho sakta hai... =>so better is that you 
clear your dp vector from the main fn ..


------bottom up------
LHS nikalne ke liye aapko RHS compute karna hoga => to compute the ith index you need to find the
i+1 and i+2th index first...

*/

