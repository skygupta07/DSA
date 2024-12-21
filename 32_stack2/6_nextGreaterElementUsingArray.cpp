#include <iostream>
using namespace std;


int main(){
    int arr[]={3,1,2,4,5,6,3};  // 4 2 4 5 6 -1 -1 
    int n = sizeof(arr)/sizeof(arr[0]);
    int nge[n];

    for (int i=0; i<n; i++){
        nge[i]=-1;  // chalaki ki sabko hi initially -1 se initialise kar diya
                    //  now ab aap me dum hai to badal lo...
        for (int j=i+1; j<n; j++){
            if (arr[j]>arr[i]){
                nge[i]=arr[j];
                break; // just next greater hi element chahiye isliye break karenge 
                        // otherwise ussey bhi bade se value update ho sakti hai..
            }
        }
    }

    for (int i=0; i<n; i++){
        cout<<nge[i]<<" ";
    }
    cout<<endl;

}