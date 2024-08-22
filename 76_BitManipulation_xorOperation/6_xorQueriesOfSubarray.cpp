#include <iostream>
#include <vector>
using namespace std;
int main(){

}

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        
        for (auto q : queries){
            int xorr = 0;   // reason zero xor anything is anything...
            for (int i=q[0]; i<=q[1]; i++){
                xorr ^= arr[i]; 
            }
            ans.push_back(xorr);
        }

        return ans;
    }
};


/*
reason: xor aapka commutative property hota hai....

sum karte waqt sum = 0 se initialise 
multiply karte waqt prod = 1 se initialise

xor karte waqt xorr = 1    se initialise

*/