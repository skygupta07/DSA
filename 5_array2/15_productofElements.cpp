#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number of elements: ";
    cin>>n;
    int arr[n];
    int prod=1;

    cout<<"enter the elements of array: ";
    for (int i=0; i<n; i++){
        cin>>arr[i];

        prod = prod*arr[i];
    
    }

    cout<<"product of all the arrays element is: "<<prod<<endl;

    
    

}