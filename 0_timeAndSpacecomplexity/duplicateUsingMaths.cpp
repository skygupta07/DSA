#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,2};
    int sum =0;
    int n = 6;

    for (int i=0; i<7; i++){
        sum+=arr[i];

    }

    int s = n*(n+1)/2;
    cout<<"duplicate element is: "<<sum-s <<endl;

    
}