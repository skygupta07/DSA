// minimumCostToCutBoardIntoSquares.cpp


/*

A board of length m and width n is given. 
The task is to break this board into m*n squares such that cost of breaking is minimum. 
The cutting cost for each edge will be given for the board in two arrays x[] and y[]. 
In short, you need to choose such a sequence of cutting such that cost is minimized. 
Return the minimized cost.


Examples

Input: m = 6, n= 4, x[] = {2, 1, 3, 1, 4}, y[] = {4, 1, 2}
Output: 42


Explanation: 

For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is 
evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces

Cost 4 Horizontal cut:      Cost = 0 + 4*1 = 4
Cost 4 Vertical cut:        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut:        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut:      Cost = 18 + 2*3 = 24
Cost 2 Vertical cut:        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut:      Cost = 30 + 1*4 = 34
Cost 1 Vertical cut:        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut:        Cost = 38 + 1*4 = 42
 
Input: m = 4, n = 4 x[] = {1, 1, 1} y[] = {1, 1, 1}
Output: 15


Explanation: 

For above board optimal way to cut into square is:
Total minimum cost in above case is 15.
It is evaluated using following steps.


Initial Value : 
Total_cost = 0 Total_cost = Total_cost + edge_cost * total_pieces

Cost 1 Horizontal cut: Cost = 0 + 1*1 = 1
Cost 1 Horizontal cut: Cost = 1 + 1*1 = 2
Cost 1 Horizontal cut: Cost = 2 + 1*1 = 3
Cost 1 Vertical cut:   Cost = 3 + 1*4 = 7
Cost 1 Vertical cut:   Cost = 7 + 1*4 = 11
Cost 1 Vertical cut:   Cost = 11 + 1*4 = 15


Your Task:  
You don't need to read input or print anything. 
Your task is to complete the function minimumCostOfBreaking() which takes a string s 
and returns an integer as output.


Expected Time Complexity: O(NlogN + MlogM)
Expected Auxiliary Space: O(1)

Constraints:
m <= 105, 2 <= n

*/




