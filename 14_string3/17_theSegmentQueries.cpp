#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long int> user_logic(int n, int q, vector<long long int>& arr, vector<vector<string>>& queries) {
    long long int a=0;
    vector<long long int> v;

    for(int i=0;i<n;i++){
        a += arr[i];
    }

    for(int i=0;i<q;i++){
        if(queries[i][0]=="?"){
            v.push_back(a);
        }

        else{
            a+=stoll(queries[i][3])*(stoll(queries[i][2])-stoll(queries[i][1])+1);
        }
    }

    return v;
}

int main() {
    int t, n, q;
    cin >> t;
    
    vector<long long int> results;
    
    for (int i = 0; i < t; ++i) {
        cin >> n >> q;
        
        vector<long long int> arr(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        
        vector<vector<string>> queries(q);
        for (int k = 0; k < q; ++k) {
            string query_type;
            cin >> query_type;
            if (query_type == "!") {
                string l, r, m;
                cin >> l >> r >> m;
                queries[k] = {query_type, l, r, m};
            } else {
                queries[k] = {query_type};
            }
        }
        
        vector<long long int> result = user_logic(n, q, arr, queries);
        results.insert(results.end(), result.begin(), result.end());
    }
    
    for (const long long int& res : results) {
        cout << res << endl;
    }
    
    return 0;
}