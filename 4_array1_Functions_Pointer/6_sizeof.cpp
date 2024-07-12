#include <iostream>
using namespace std; 
int main(){
    int arr[]={4,6,7,8,12,34,5,6,89};
    int arrsize = sizeof(arr); // matlab array kitna bit ki space le rha h memory mai...
    cout<<arrsize<<endl;

    int arrsize2 = sizeof(arr)/sizeof(arr[0]);
    cout<<arrsize2<<endl;


    
    
}