//lc 2182. Construct String With Repeat Limit

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;



class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map <char,int> mp;
        for (int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        priority_queue < pair <char,int> > pq;
        for (auto p: mp){
            pq.push(p);
        }
        
        string result = "";
        while (!pq.empty()){
            auto largest = pq.top();   //since max heap
            pq.pop();

            int len = min(repeatLimit , largest.second);
            for (int i=0; i<len; i++){
                result += largest.first;    // largest.first gives character
            }
            pair <char,int> secondLargest;
            
            if (largest.second - len > 0){  // checking whether first character has anymore occurences or not
                if (!pq.empty()){
                    secondLargest = pq.top();
                    pq.pop();
                    result += secondLargest.first;
                }
                else return result;

                if(secondLargest.second - 1 > 0) pq.push({secondLargest.first, secondLargest.second - 1});
                pq.push({largest.first, largest.second - len}); 
            }
        }

   


        



















        return result;
    }
};

/*
first of all try to include max repeat limit of first lexicographically largest 
and then give partition of second lexicographically largest char and 
then again first lexicographically largest then second and so on 
..until first exhaust then second will be in main role and third as partition

so better to use max heap with pair <char, freq>  and then repeat the process for freq - k 

// priority queue or map mai se element nikalna easy...simply auto ka use kiya..

for auto p in mp try pq.push(s[i]);

*/














int main(){


}
























/*
lexicographically -> matlab dictionary Order

// lexicographically larger wale element ko place kiya k times then 2nd largest available 
lexicographic element ko singly place kiya then first wala fill kiya repeat until
the very first element exhausts then repeat the process for 2nd largest available element\



\\\\\
\


*/