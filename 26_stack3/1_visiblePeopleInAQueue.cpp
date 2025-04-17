/*

There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

 

Example 1:



Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
Example 2:

Input: heights = [5,1,2,3,10]
Output: [4,1,1,1,0]
 

Constraints:

n == heights.length
1 <= n <= 105
1 <= heights[i] <= 105
All the values of heights are unique.
*/

#include <iostream>
using namespace std;
int main(){

}


/*
taller element can replace the shorter person from the stack
total number of persons replace from the stack is the number of person he can see..

if the stack is not empty then add one more to the result....
reason-> apne bagal wale element ko to dekh hi sakta hai...
starting from the right end 
technique is : pop ans push

*/


class Solution {
    public:
        vector<int> canSeePersonsCount(vector<int>& heights) {
            int n = heights.size();
    
            // Answer vector jisme har person ke liye count of visible persons store karenge
            vector<int> ans(n, 0);
    
            // Stack use kar rahe hain to keep track of heights on the right side
            // Yeh stack decreasing order mein hoga — top par sabse chhota banda hoga jo abhi tak dikha hai
            stack <int> stk;
    
            // Right to left loop: kyunki har person ko apne right wale log dekhne hain
            for (int i = n - 1; i >= 0; i--) {
                int visible = 0;  // is bande ko kitne log dikhenge
    
                // Jab tak stack empty nahi hai aur current height > top of stack
                // iska matlab jo stack mein hai woh chhota hai toh woh visible hoga
                // usko count kar lo aur stack se hata do
                while (!stk.empty() && heights[i] > stk.top()) {
                    stk.pop();
                    visible++;  // har pop matlab ek banda visible tha
                }
    
                // Ab agar koi aur banda stack mein bacha hai
                // toh woh bada ya barabar hoga current person se — woh bhi dikhega
                // lekin uske baad koi aur nahi dikhega because he will block the view
                if (!stk.empty()) visible++;
    
                // current person ke liye visible count store karo
                ans[i] = visible;
    
                // Apne aapko stack mein push kar lo
                // kyunki left mein jo bhi banda aayega usko hum dikhayenge
                stk.push(heights[i]);
            }
    
            return ans;  // final answer vector return karo
        }
    };






