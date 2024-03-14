// Find the unique number in a given Array where all the elements are being repeated twice with one
// value being unique.

#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,5,6,3,2,4};
    // 11223345566
    
    int n = sizeof(arr)/sizeof(arr[0]);
    // sort using bubble sort
    // compare by applying neighbour wali condition.
    //print


    for (int i=0; i<n-1; i++){ // n-1 times andar wala loop chalega...
        for (int j=0; j<n-1-i; j++){  // n-1-i times tak hi kyuki har loop me ek element to finally last me
                                        // apni position par chala ja rha h

            if (arr[j]>arr[j+1]){
                swap (arr[j],arr[j+1]);


            }

        }
    }
    for (int i=0; i<n; i++){  // since we are printing the elements..so i varies
                                // from 1 to n
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bool flag = 0;
    int ans;
    for (int i=0; i<n; i++){
         // flag =0 means no unique element
        if (arr[i]==arr[i-1] || arr[i]==arr[i+1]){
            flag = 0;
            continue;   
        }
       
        else{
            ans = arr[i];
            flag = 1;
            break;
        }
        
    }
        if (flag == 0){
            cout<<"no unique element is present in the array... "<<endl;
        }
        else{
            cout<<"unique element in the array is: "<<ans<<endl;
        }
        
    
}














