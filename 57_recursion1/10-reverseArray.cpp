#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rev(int arr[], int i, int j){
    if (i > j) return;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

    rev(arr,i+1,j-1);
}


int main(){
    int arr[] = {5,3,1,8,10,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    print(arr,n);
    rev(arr,0,n-1);
    print(arr,n);
}





// recursive fn likh ke dekh lo...






/*
stack overflow occurs when there are numerous fn call waiting in stack due to recursion..
so it is necessary to include the base cases wisely 


*/