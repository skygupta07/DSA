// candy.cpp

#include <bits/stdc++.h>
using namespace std;


/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.


Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

*/



class Solution {
public:
    
     int candy(vector <int> &ratings){
        int size = ratings.size(); // yes size name bhi rakh sakte ho..
        if(size <= 1) return size;

        vector <int> num(size,1);

        // I love this pattern jisme {1 se start karte h loop and 
        // curr aur prev compare karte h and action lete h}
        for (int i = 1; i < size; i++){

            // if curr rating is greater than prev rating {then bhai prev wale se ek jyada mai bhi to deserve karta hu.}
            if(ratings[i] > ratings[i-1]) num[i] = num[i-1]+1;
        }

        // peeche se loop chalaya 
        for (int i=size-1; i>0 ; i--){
            // if current rating is less than prev rating -- then bhai prev person bhi mere se ek jyada agar deserve karta h to rakh le ek jyada 
            // mujhe koi dikkat nahi h ..
            if(ratings[i] < ratings[i-1]) num[i-1] = max(num[i] + 1, num[i-1]);
        }

        int result=0;

        for (int i = 0; i < size; i++){
            result += num[i];
        }

        return result;
        
     }
    
};