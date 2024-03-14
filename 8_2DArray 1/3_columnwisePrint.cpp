#include <iostream>
using namespace std; 
int main(){
    int arr[3][3]={1,2,3,
                    4,5,6,
                    7,8,9};
    // print our matrix
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++) cout<<arr[i][j]<<" "; 
        cout<<endl;    
    }

    cout<<endl<<"printing matrix columnwise "<<endl;

    for (int j=0; j<3; j++){ 
            for (int i=0; i<3; i++) cout<<arr[i][j]<<" ";
            cout<<endl;  
    }

}












// jaise hi break statement encounter hoga uss loop ke saare next iteration ko tata bye 
// though agar uske bahar koi loop hai to uski next value ke to chalega inner loop