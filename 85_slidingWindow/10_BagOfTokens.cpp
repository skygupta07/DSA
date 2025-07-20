// bagOfTokens.cpp

#include <bits/stdc++.h>
using namespace std;

/*
You start with an initial power of power, an initial score of 0,
 and a bag of tokens given as an integer array tokens, 
 where each tokens[i] donates the value of token i.
 
Your goal is to maximize the total score by strategically playing these tokens.
In one move, you can play an unplayed token in one of the two ways (but not both for the same token):

Face-up: If your current power is at least tokens[i], you may play tokeni,
losing tokens[i] power and gaining 1 score.

Face-down: If your current score is at least 1, you may play tokeni,
gaining tokens[i] power and losing 1 score.

Return the maximum possible score you can achieve after playing any number of tokens.

 

Example 1:

Input: tokens = [100], power = 50

Output: 0

Explanation: Since your score is 0 initially, you cannot play the token face-down. 
You also cannot play it face-up since your power (50) is less than tokens[0] (100).

Example 2:

Input: tokens = [200,100], power = 150

Output: 1

Explanation: Play token1 (100) face-up, reducing your power to 50 and increasing your score to 1.

There is no need to play token0, since you cannot play it face-up to add to your score. 
The maximum score achievable is 1.

Example 3:

Input: tokens = [100,200,300,400], power = 200

Output: 2

Explanation: Play the tokens in this order to get a score of 2:

Play token0 (100) face-up, reducing power to 100 and increasing score to 1.
Play token3 (400) face-down, increasing power to 500 and reducing score to 0.
Play token1 (200) face-up, reducing power to 300 and increasing score to 1.
Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
The maximum score achievable is 2.

*/


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {

        sort(tokens.begin(), tokens.end()); // smaller tokens in beginning , larger at end...
        int maxScore = 0;
        int currScore = 0;

        int i = 0;
        int j = tokens.size() - 1;

        while (i <= j){
            if (power >= tokens[i]){
                currScore++;
                power -= tokens[i++];
                maxScore = max(maxScore ,currScore);
            }
            else if (currScore > 0){
                currScore--;
                power += tokens[j--];
                // maxScore = max(maxScore ,currScore);          // iss case mai score ghat raha hai to yaha max check karne ki waise koi need nahi hai..

            }
            else{
                break;
            }
        }

        return maxScore;     
    }
};

/*

two pointer greedy thinking...

apna score badhane ke liye best way is to give min. cost chocolate to mam each time... 
so that you could give more number of chocolates and increase your marks rapidly....

when I am decreasing my score just to take token values 
then for sure I will take the most costly token(or chocolate) that time. 
taaki ab us chocolate ko next round mai use karke score badha saku....

maintain currScore and maxScore also....

once any token value is used simply move to next token....

*/