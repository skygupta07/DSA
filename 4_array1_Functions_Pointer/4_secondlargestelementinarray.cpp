#include <iostream>
using namespace std; 
int main(){
    int arr[5];
    cout<<"enter the elements of array: ";
    for (int i=0; i<=4; i++){
        cin>>arr[i];     //taking input arrays element

    }
    
    for (int i=0; i<=4; i++){
        cout<<arr[i]<<" ";  //printing elements of array 

    }
    cout<<endl;
    int max= INT_MIN;
    for (int i=0; i<=4; i++){
        if (arr[i]>max){   // to find max element 
            max = arr[i];
        }
    }

    cout<<"maximum element is: "<<max<<endl;
    int smax = INT_MIN;     // better to take standard numbers instead of arr[0]
    for (int i=0; i<=4;i++){
        if (arr[i]!=max && arr[i]>smax){
            smax = arr[i];
        }
    }

    cout<<"second maximum element is: "<<smax<<endl; 



    // two pass method
}


