#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {    //O(nlogn) -> due to sorting
        int boat = 0;
        sort(people.begin() , people.end());
        int n = people.size();
        int i =0;
        int j = n-1;
        while (i<=j){
            if (people[i] + people[j] <= limit){
                boat++;
                i++;
                j--;
            } 
            else{   // send motu alone
                boat++;
                j--;
            }
        }


        return boat;
        
    }
};

/*
sort the people array
two pointer algorithm can be used -> i on front and j on end
to utilise min. no . of boats keep motu and patlu together 
try if motu and patlu can be put together if yes then put else send motu alone and boat++

*/

int main(){

}