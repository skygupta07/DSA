#include <iostream>
using namespace std; 

int main(){
    // while declaring arr[alpha][beta] => 2d vector banao jisme alpha number of rows hongi
                                // and beta number of column...
    int arr[2][3] = {1,2,3,   // first row
                     4,5,6};    // second row     
    cout<<arr[0][1]<<endl;  // while printing alpha beta are the valid indices...
    // alpha row ke beta index wale element ko leke aao...

    int brr[3][2] = {{1,2},
                     {3,4},
                     {5,6}};  // since 2d array is array of arrays
                                // or declare by distinguishing each row packed in
                        // curly braces and each row separated by comma....
    cout<<brr[1][1]<<endl;

}

/*
2d vector => pakka hai two dimension to lega hi confirm hai...

*/