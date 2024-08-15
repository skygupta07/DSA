#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveNotes = 0;
        int tenNotes = 0;

        for (int i=0; i<bills.size(); i++){

            if (bills[i] == 5) fiveNotes++;

            else if (bills[i] == 10){
                if (fiveNotes >= 1){    // there should be atleast one fiveNote
                    tenNotes++;
                    fiveNotes--;
                } 
                else return false;
            }

            else if (bills[i] == 20){
                if (tenNotes >= 1 && fiveNotes >= 1){
                    tenNotes--;
                    fiveNotes--;
                }
                
                else if (fiveNotes >= 3){
                    fiveNotes -= 3;
                }

                else return false;
            }
        }

        return true;
        
    }
};



/*
5, 10 , 20 ka note aayega...
if 5 note come -> countfiveNotes++

if 10 note come -> countTenNotes++ iff there is atleast one fiveNote also available ..

if 20 noted come -> go ahead iff 
            you have either 1 tenNote and 1 fiveNote atleast...
            or 
            you have 3 fiveNotes.....


finally return true;
*/