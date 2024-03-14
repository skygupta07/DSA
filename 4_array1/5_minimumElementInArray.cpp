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
    int min  = arr[0];   // by default hum pehle yahi maan kar chalenge
    for (int i=0; i<=4; i++){
        if (arr[i]<min){   //imp
            min = arr[i];       // left variable(min) ko update karke RHS ke equal kar do
        }
    }

    cout<<"minimum element in the array is: "<<min<<endl;
    
}