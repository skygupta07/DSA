#include <iostream>
#include <vector>

using namespace std;
int main(){
    int a[2][3]={1,3,5,
                 7,2,4};

    int b[2][3]={6,9,10,
                 12,15,3};
    int c[2][3];
    

   // how to find no. of rows and no. of columns of matrix declaration 
            //using array of arrays(2d array)
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){  // adding matrix a and b into c
            c[i][j]=a[i][j]+b[i][j];
        }
    }

    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){ // display resultant matrix
            cout<<c[i][j]<<" ";

        }
        cout<<endl;
    }

}

/*
-> 2d array used when instead of list you need somewhat table
-> garbage value given when variable not initialised

*/