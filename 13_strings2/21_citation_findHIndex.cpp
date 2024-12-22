#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        sort(citations.begin(), citations.end());
        
        int hIndex = 0;
        
        for (int i=0; i<n; i++){
            int hCandidate = n - i;
            
            if (citations[i] >= hCandidate){
                hIndex = hCandidate;
                break;
            }
        }
        
        return hIndex;
    }
};