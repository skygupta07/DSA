// leetcode 867
#include <iostream>
using namespace std;
vector <vector<int> > transpose(vector <vector<int> > &matrix){
        vector <vector<int> > transpose;
        int m=matrix.size();    // gives number of rows
        int n=matrix[0].size(); // gives number of columns

        for (int i=0; i<n;i++){
            for (int j=0; j<m; j++){
                transpose[i][j]=matrix[j][i];
            }

        }
        return transpose;
}



int main(){
    int matrix[2][3]={1,3,5,4,2,9};
    
   

}




/*
I know how to convert 1d array into vector
but how we can convert 2d array into 2d vector...


matrix transpose karne mai 2 cheeze hoti hai :->
1. no. of rows become no. of column
2. matlab ab transpose ke [i][j] mai actually matrix ka [j][i] jaega...

*/
