#include <iostream>
using namespace std;

// function to print the matrix
void printmatrix(int arr[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";

        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    int rows = sizeof(arr)/sizeof(arr[0]);  // to find no. of rows in 2d array
    int cols = sizeof(arr[0])/sizeof(arr[0][0]); // to find no. of columns in 2d array

    cout << rows <<" "<<cols <<endl<<"\n";

    // to rotate the matrix by 90 degrees...
    //step1 transpose lo
    // step2 har row ko reverse kar do.

    cout<<"matrix is:"<<endl;
    printmatrix(arr);
    cout<<endl;

    int t[3][3];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            t[i][j]=arr[j][i];  // taking transpose
        }
        
    }
    // cout<<"transpose matrix is:"<<endl;
    // printmatrix(t);

    for (int k=0; k<3; k++){  //reversing elements of each row..
        int i=0;
        int j=3;
        while (i<=j){
            int t=arr[k][i];
            arr[k][i]=arr[k][j];
            arr[k][j]=t;
            i++;
            j--;    
        }

    }
    cout<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        
    }
        

    }

    
