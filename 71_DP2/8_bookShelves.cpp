// bookShelves.cpp

/*

You are given an array books where books[i] = [thicknessi, heighti] 
indicates the thickness and height of the ith book. 
You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness 
is less than or equal to shelfWidth, then build another level of the shelf of the bookcase 
so that the total height of the bookcase has increased by the maximum height of the books 
we just put down. We repeat this process until there are no more books to place.


Note that at each step of the above process, 
the order of the books we place is the same order as the given sequence of books.


For example, if we have an ordered list of 5 books, we might place the first and second book 
onto the first shelf, the third book on the second shelf, 
and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be 
after placing shelves in this manner.


Example 1:

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6

Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.


Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4
 

Constraints:

1 <= books.length <= 1000
1 <= thicknessi <= shelfWidth <= 1000
1 <= heighti <= 1000

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

                            // thickness, height
    int minHeightShelves(vector<vector<int>> &books, int shelf_width){
        int n = books.size();

        // dp[i] = minimum height of bookshelf for the first i books
        // n+1 isliye coz my number of books can range from 0 to n
        // why initialise with INT_MAX - coz actually I need to find the minimum height of bookshelf..so 
        // initially all initialise with INT_MAX..

        vector <int> dp(n + 1, INT_MAX);

        // Base case: 0 books take 0 height
        dp[0] = 0;

        // Loop over each book position j (1-based for dp indexing)
        for (int j = 1; j <= n; j++){

            int curWidth = 0;   // Total width of books on current shelf
            int maxHeight = 0;  // Max height of any book on current shelf


            // Try placing books from j-1 to i on the same shelf
            for (int i = j; i >= 1; i--) {
                curWidth += books[i - 1][0];           // Add width of book[i-1]
                
                if (curWidth > shelf_width) break;     // Exceeds shelf width, can't place more

                maxHeight = max(maxHeight, books[i - 1][1]);  // Track tallest book
                
                dp[j] = min(dp[j], dp[i - 1] + maxHeight);    // Update minimum height
            }

        }

        // Minimum height for all n books
        return dp[n];  
        
    }
};
