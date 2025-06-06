#include <bits/stdc++.h>
using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],
                [4,5,6],
                [7,8,9]]

Output: [1,2,3,6,9,8,7,4,5]
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();   // to calculate the number of rows 
    int n = matrix[0].size(); // to calculate the number of columns
    
    int minr=0;
    int maxr=m-1;
    
    int minc=0;
    int maxc=n-1;
    
    int tne = m*n;  // tne = total number of elements..
    int count =0;
    vector <int> v;


    
    // steps: right, down, left, up....

    while (minr <= maxr and minc <= maxc){
        //right
        for (int j=minc; j<=maxc; j++){
            v.push_back(matrix[minr][j]);
        }
        minr++;

        if (minr > maxr || minc> maxc ) break;      // break as soon as condition violate ho...(har loop ke baad )
        
        
        //down
        for (int i=minr; i<=maxr; i++){
            v.push_back(matrix[i][maxc]);
        }
        maxc--;


        //left 
        if (minr > maxr || minc> maxc ) break;
        for (int j=maxc; j>=minc; j--){
            v.push_back(matrix[maxr][j]);
        }
        maxr--;


        //up
        if (minr > maxr || minc> maxc ) break;
        for (int i=maxr; i>=minr; i--){
            v.push_back(matrix[i][minc]);

        }
        minc++;


    }  
    return v;
}
};

// 


class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        int minr = 0;
        int maxr = r - 1;
        
        int minc = 0;
        int maxc = c - 1;
        
        vector <int> ans;
        
        while (minr <= maxr && minc <= maxc){
            // right -> col varies
            for (int j=minc; j<=maxc; j++){
                ans.push_back(mat[minr][j]);
            }
            minr++;
            
            if (minr > maxr || minc > maxc) break;
            
            // down -> row varies
            for (int i=minr; i<=maxr; i++){
                ans.push_back(mat[i][maxc]);
            }
            maxc--;
            
            if (minr > maxr || minc > maxc) break;
            
            // left -> col varies
            
            for (int j=maxc; j>=minc; j--){
                ans.push_back(mat[maxr][j]);
            }
            maxr--;
            
            if (minr > maxr || minc > maxc) break;
            
            // up -> row varies
            
            for (int i=maxr; i>=minr; i--){
                ans.push_back(mat[i][minc]);
            }
            minc++;
            
            
            if (minr > maxr || minc > maxc) break;
        }
        
        return ans;
    }
};
