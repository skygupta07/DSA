#include <bits/stdc++.h>
using namespace std;

/*


Given two integer array A and B of size N each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum K valid sum combinations from all the possible sum combinations.

Note : Output array must be sorted in non-increasing order.

Example 1:

Input:
N = 2
K = 2
A [ ] = {3, 2}
B [ ] = {1, 4}
Output: {7, 6}
Explanation: 
7 -> (A : 3) + (B : 4)
6 -> (A : 2) + (B : 4)


Example 2:

Input:
N = 4
K = 3
A [ ] = {1, 4, 2, 3}
B [ ] = {2, 5, 1, 6}
Output: {10, 9, 9}
Explanation: 
10 -> (A : 4) + (B : 6)
9 -> (A : 4) + (B : 5)
9 -> (A : 3) + (B : 6)


Your Task:
You don't need to read input or print anything. 
Your task is to complete the function maxCombinations() which takes the interger N,integer K 
and two integer arrays A [ ] and B [ ] as parameters and returns 
the maximum K valid distinct sum combinations .

Expected Time Complexity: O(Nlog(N))
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤  105
1 ≤ K ≤  N
1 ≤ A [ i ] , B [ i ] ≤ 104

*/


class Solution { // gives tle
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        vector <int> ans;
        
        priority_queue <int> pq;
        
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                pq.push(A[i] + B[j]);
            }
        }
        
        while (!pq.empty() && K--){
            int sum = pq.top();
            pq.pop();
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        
        // sum , {indexA ,indexB}
        priority_queue < pair <int, pair <int,int>>> pq; 

        pq.push( { (A[0] + B[0]), {0 , 0} });
        
        set <pair <int, int>> visited;  // indexA, indexB
        visited.insert({0,0});
        
        vector <int> ans;
        
        while (!pq.empty() && K--){
            auto top = pq.top();  // ha top bhi likh sakte h as a variable name , singh ne bataya tha..
            pq.pop();
            
            int sum = top.first;

            // i, j index yaha fetch kiya..
            int i = top.second.first; 
            int j = top.second.second;
            
            ans.push_back(sum);
            
            // push the next pair i+1, j
            
            if (i+1 <= N-1 && visited.find({i+1, j}) == visited.end()){
                pq.push( { A[i+1] + B[j], {i+1, j} });
                visited.insert({i+1, j});
            }
            
            // push the next pair i , j+1
            
            if (j+1 <= N-1 && visited.find({i, j+1}) == visited.end()){
                pq.push( { A[i] + B[j+1], {i, j+1} } );
                visited.insert({i, j+1});
            }
        }
        
        return ans;
    }
};


/*

sort A, B in descending order 
max sum  is A[0] + B[0] -> threshold

yaha pura heap suru mai hi nahi bana diya bas simply threshold daal ke operation 
karte huye hi .... heap ko bhi compute kar rahe h...

now confusion tha na ki kiska pointer badhau.. A ka ya B ka .. to phir simply
A ka ek pointer aage karo ... and next step mai B ke pointer ko aage karke bhi 
consider kara...


*/
