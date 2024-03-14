#include <iostream>
using namespace std;

void prefixSum(int arr[], int n){
    int psum[n];
    psum[0] = arr[0];

    for (int i=1; i<n; i++){
        psum[i] = arr[i] + psum[i-1];
    }
    for(int i=0; i<n; i++){
        cout<<psum[i]<<" ";
    }
    cout<<endl;
}

void suffixSum(int arr[], int n){
    int sSum[n];
    sSum[n-1] = arr[n-1];

    for (int i=n-2; i>=0; i--){
        sSum[i] = arr[i] + sSum[i+1];
    }
    for(int i=0; i<n; i++){
        cout<<sSum[i]<<" ";
    }
    cout<<endl;
}

void prefixProduct(int arr[], int n){
    int pProd[n];
    pProd[0] = arr[0];

    for (int i=1; i<n; i++){
        pProd[i] = arr[i] * pProd[i-1];
    }
    for(int i=0; i<n; i++){
        cout<<pProd[i]<<" ";
    }
    cout<<endl;
}


void suffixProduct(int arr[], int n){
    int sProd[n];
    sProd[n-1] = arr[n-1];

    for (int i=n-2; i>=0; i--){
        sProd[i] = arr[i] * sProd[i+1];
    }
    for(int i=0; i<n; i++){
        cout<<sProd[i]<<" ";
    }
    cout<<endl;
}

void prefixProductExceptSelf(int arr[],int n){
    int ppes[n];
    ppes[0] = 1;
    for (int i=1; i<n; i++){
        ppes[i] = ppes[i-1]*arr[i-1];
    }
    for (int i=0; i<n; i++){
        cout<<ppes[i]<<" ";
    }
    cout<<endl;
}

void suffixProductExceptSelf(int arr[],int n){
    int spes[n];
    spes[n-1] = 1;
    for (int i=n-1; i>=0; i--){
        spes[i] = spes[i-1]*arr[i-1];
    }
    for (int i=0; i<n; i++){
        cout<<spes[i]<<" ";
    }
    cout<<endl;
}





int main(){
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"prefix sum is:\n";
    prefixSum(arr,n);

    cout<<"suffix sum is:\n";
    suffixSum(arr,n);

    cout<<"prefix product is:\n";
    prefixProduct(arr,n);

    cout<<"suffix product is:\n";
    suffixProduct(arr,n);

    cout<<"prefix product except self is: \n";
    prefixProductExceptSelf(arr,n);
    




}



/*
nums =        [1,2,3,4]
prefixSum =   [1,3,6,10]
suffixSum =   [10,9,7,4]

prefixProduct = [1,2,6,24];
suffixProduct = [24,24,12,4];
productExceptSelf= [24,12,8,6]


nums =                    [1,2,3,4]
prefixProductExceptSelf = [1,1,2,6]
suffixProductExceptSelf = [12,12,4,1]



 [24,12,8,6]

*/
