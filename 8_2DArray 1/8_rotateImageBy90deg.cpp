#include <iostream>
using namespace std;
int main(){

}

class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        // to rotate by 90 degree first take transpose then reverse each row..
        int n = arr.size();
        
        // for transpose 
        for (int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){ // starting from i+1 to avoid rechanging it to original
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;    
            }
        }

        // reverse each row

        // row ko fix karke then uske corresponding column wale elements ko replace kar do...
        for (int k =0; k<n; k++){ // traversing each row ek ke neeche wala ek
            int i = 0;  // first pointer at 0th element
            int j = n-1;    // second pointer at last indexed element of that row..
            
            while (i<=j){
                int temp = arr[k][i];
                arr[k][i] = arr[k][j];  // k to fix rahega same row ke liye now ab 
                                        //aage column me badho with help of i and j

                arr[k][j] = temp;

                i++;
                j--;

            }
        }
        return;
    }
};