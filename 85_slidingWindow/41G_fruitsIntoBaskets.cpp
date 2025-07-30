// fruitsIntoBaskets.cpp

#include <bits/stdc++.h>
using namespace std;

/*

You are visiting a farm that has a single row of fruit trees arranged from left to right. 
The trees are represented by an integer array fruits
where fruits[i] is the type** (Akash Not number) of fruit the ith tree produces.

You want to collect as much fruit as possible. 
However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.

Starting from any tree of your choice, you must pick exactly one fruit from every tree
(including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.

Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.


Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 1e5
0 <= fruits[i] < fruits.length

*/



// return top 2 most frequent fruits - wrong Answer {kyuki aapne yaha stop wali condition ignore kari..}
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map <int, int> freq;
        for (auto fruit : fruits) freq[fruit]++;

        // minheap
        priority_queue <int, vector <int>, greater <int> > pq;

        for (auto el : freq){
            pq.push(el.second);

            if (pq.size() > 2) pq.pop();
        }

        int ans = pq.top();
        pq.pop();

        ans += pq.top();
        pq.pop();

        return ans;
    }
};

/*

Wrong Answer
30 / 91 testcases passed
submitted at May 12, 2025 02:59

Editorial
Input

fruits =
[3,3,3,1,2,1,1,2,3,3,4]

Use Testcase
Output
8

Expected
5

*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map <int, int> basket; // key - type of fruit, value - number of fruit
        int left = 0, maxLen = 0;

        // right wala pointer chup chap start se end tak jaata h...aur left wala pointer adjust karta h..
        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;

            // Jab basket mein 2 se zyada types aa jaaye, window shrink karo
            while (basket.size() > 2) {
                basket[fruits[left]]--;

                if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
                
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
