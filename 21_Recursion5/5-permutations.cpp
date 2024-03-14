/*

class Solution {
public:
    void p(vector<int>&arr, vector<vector<int>>&ans, vector <int>&ds, vector <int> &mp){
        if (ds.size() == arr.size()){
            ans.push_back(ds);
            return;
        }
        // calculate hash array or simple vector to store the acknowledgement whether taken the element or not..
        for (int i=0; i<arr.size(); i++){
            if (!mp[i]){   // or if (map[i] == 0) -> i.e. the element has not been taken for corresponding step
                ds.push_back(arr[i]);
                mp[i] = 1;
                p(arr,ans,ds,mp);   // recursive call
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& arr){
        int n = arr.size();
        vector<vector<int>> ans;
        vector <int> ds;
        vector<int> mp(n);
        for (int i=0; i<mp.size(); i++) mp[i] = 0;
        p(arr,ans,ds,mp);
        return ans;
    }
};

*/