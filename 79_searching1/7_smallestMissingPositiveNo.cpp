#include <iostream>
using namespace std;

int main(){
    int arr[] = {0,1,2,3,6,7,8};    // given sorted arr
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=1; i<n; i++){
        if (arr[i] == arr[i-1]+1) continue;
        else{
            cout<<arr[i-1]+1 <<endl;
            break;
        }
    }
}


