#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.length();
        int count = 1;


        for (int i=1; i<n; i++){
            if (word[i] == word[i-1]){
                count++;
            }

            else{   // if streak breaked by word[i] matlab word[i-1] tak streak bani thi...
                while (count > 0){
                    int chunk = min(9, count);
                    
                    ans += to_string(chunk) + word[i-1];
                    count -= chunk;
                }
                count = 1;  // reset count to 1 again for next upcoming characters...
            }

        }

        // there will be no one to break the streak of last consecutive element so do it again for him..

        while (count > 0){
            int chunk = min(9, count);
            ans += to_string(chunk) + word[n-1];
            count -= chunk;
        }
        
        return ans;
    }
};


/*
count = 1 maan ke chala ...
i = 1 se start kara.... 


jab tak streak ban rahi hai maintain karo....
and jaise hi streak break kare ...koi character to count karna start kar do chunks and start 
making the answer string as well...

*/