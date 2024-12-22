#include <bits/stdc++.h>
using namespace std;

/*
you are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
Return the generated matrix.

Example 1:
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.

*/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) 
    {
		// Create a matrix of n x m with values filled with -1.
        vector<vector<int>> spiral(n, vector<int>(m, -1));
        int i = 0, j = 0;
		// Traverse the matrix in spiral form, and update with the values present in the head list.
		// If head reacher NULL pointer break out from the loop, and return the spiral matrix.
        while (head != NULL)
        {
            if (j < m)
            {
                while (head != NULL && j < m && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    j++;
                }
                if (head == NULL)
                    break;
                i++;
                j--;
            }
            if (i < n)
            {
                while (head != NULL && i < n && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    i++;
                }
                i--;
                j--;
            }
            if (j >= 0)
            {
                while (head != NULL && j >= 0 && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    j--;
                }
                j++;
                i--;
            }
            if (i >= 0)
            {
                while (head != NULL && i >= 0 && spiral[i][j] == -1)
                {
                    spiral[i][j] = head->val;
                    head = head->next;
                    i--;
                }
                i++;
                j++;
            }
            n--;
            m++;
        }
		// Rest values are itself -1.
        return spiral;
    }
};