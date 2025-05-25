#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<string> camelCase(vector <string> &arr, string &pat) {
        vector <string> ans;
        
        for (auto str : arr){
            string temp = "";
            
            for (auto ch : str){
                if (isupper(ch)) temp += ch;
                
                if (temp == pat) {
                    ans.push_back(str);
                    break;
                }
            }
        }
        
        return ans;
    }
};


/*
go to each string 
    then in each string store all the uppercase character in serial order...
    at every moment if the stored uppercase letter string becomes equal to the 
    pattern then store it in answer....
    
    
    return ans;


*/

