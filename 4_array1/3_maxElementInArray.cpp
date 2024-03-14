#include <iostream>
using namespace std; 
int main(){
    int arr[5];
    cout<<"enter the elements of array: ";
    for (int i=0; i<=4; i++){
        cin>>arr[i];

    }
    
    for (int i=0; i<=4; i++){
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    int max = arr[0];   // by default hum pehle yahi maan kar chalenge or max = INT_MIN
    for (int i=0; i<=4; i++){
        if (arr[i]>max){   //imp
            max = arr[i];
        }



    }

    cout<<"maximum element in the array is: "<<max;
    
}