#include <iostream>
using namespace std; 
int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    // print our matrix
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";                
        }        
        cout<<endl;        
    }


    for (int i=0; i<3; i++){  // transpose
        for (int j=0; j<3; j++){
           if (j>i){
            int t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
           }               
        }        
            
    }

    for (int i=0; i<3; i++){  // print
        for (int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";                
        }        
        cout<<endl;        
    }


    

}