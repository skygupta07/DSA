#include <iostream>
using namespace std;
int main(){
    int arr[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    cout<<"our matrix arr is: "<<endl<<endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            cout<<arr[i][j]<<" ";

        }
        cout<<endl; 
    }
    cout<<endl<<"our wave matrix is: "<<endl<<endl; 
    for (int i=0; i<3; i++){
        if (i%2==0){
            for (int j=0; j<4; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        else{ // odd ke case mai bas ulta print karna
            for (int j=3; j>=0; j--){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
                
            }

        }
        cout<<endl;
    }


/*

1 2 3 4 
5 6 7 8 
9 10 11 12 

our wave matrix is: 

1 2 3 4 
8 7 6 5 
9 10 11 12 


*/