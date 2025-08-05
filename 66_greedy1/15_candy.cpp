#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    int candy(vector <int> &ratings) {
        int n = ratings.size();

        vector <int> left(n, 1);
        vector <int> right(n, 1);

        for (int i=1; i<n; i++){
            if (ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }

        for (int j = n-2; j >= 0; j--){
            if (ratings[j] > ratings[j+1]){
                right[j] = right[j+1] + 1;
            }
        }

        int sum = 0;

        for (int i=0; i<n; i++){
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};


/*
brute force 

// consider left nbrs only
then consider right nbrs only

then add max(left, right) contribution ...

*/



// omitting right vector 
class Solution {
public:

    int candy(vector <int> &ratings) {
        int n = ratings.size();

        vector <int> left(n, 1);

        for (int i=1; i<n; i++){
            // if my rating is more than prev rating 
            if (ratings[i] > ratings[i-1]){
                // then I deserve 1 more than prev guy
                left[i] = left[i-1] + 1;
            }
        }

        for (int j = n-2; j >= 0; j--){
            // if my rating is greater than person next to me 
            if (ratings[j] > ratings[j+1]){
                // then i deserve 1 more than him {accha rahega yaha aap maximize karke cheeje karo ..}
                left[j] = max(left[j], left[j+1] + 1);
            }
        }

        int sum = accumulate(left.begin(), left.end(), 0);

        return sum;
    }

};


/*
brute force 

// consider left nbrs only
then consider right nbrs only

then add max(left, right) contribution ...

*/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        int i = 1;
        int sum = 1; // pehle bachhe ko 1 candy toh milegi hi

        while(i < n){
            
            // land surface - jab same rating ho (flat ground)
            if (ratings[i] == ratings[i-1]) {
                sum += 1; // equal rating => 1 candy
                i++;

                continue;
            }

            int peak = 1; // peak element ko abhi 1 candy denge, 
            // aage badhate rahenge agar increase mila

            // increasing slope (rating badh rahi hai)
            while(i < n && ratings[i] > ratings[i-1]) {
                
                peak += 1;        // har bar ek candy zyada
                sum += peak;      // add into total
                
                i++;
            }

            // decreasing slope (rating ghat rahi hai)
            int down = 0;
            while(i < n && ratings[i] < ratings[i-1]) {
                down += 1;        // downhill mein count badhate jao
                sum += down;      // total mein add karo
                
                i++;
            }

            // ab peak par wapas aayein (jo increasing+decreasing ke beech aata hai)
            // agar down > peak, toh peak ka contribution chhota tha, usse correct karo
            // example: peak = 3 candies, down = 4 levels => peak should be 4 candies to maintain rules
            down++; // peak element bhi down slope ka part hai
            
            if(down > peak) {
                sum += down - peak; // extra candies add karo to compensate
            }
        }

        return sum;

    }
};



