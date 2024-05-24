#include <iostream>
using namespace std; 
int main(){
    int arr[4][3]={1,2,3,
                    4,5,6,
                    7,8,9,
                    10,11,12};
    // print our matrix

    cout<<endl<<"printing matrix rowwise: "<<endl;
    for (int i=0; i<4; i++){
        for (int j=0; j<3; j++) cout<<arr[i][j]<<" "; 
        cout<<endl;    
    }

    cout<<endl<<"printing matrix columnwise "<<endl;

    for (int j=0; j<3; j++){ 
            for (int i=0; i<4; i++) cout<<arr[i][j]<<" ";
            cout<<endl;  
    }

}












// jaise hi break statement encounter hoga uss loop ke saare next iteration ko tata bye 
// though agar uske bahar koi loop hai to uski next value ke to chalega inner loop