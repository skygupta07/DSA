#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[] = {8,1,5,2,9,25,10,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int fmax  = -1, smax = -1, tmax = -1;

    for (int i=0; i<n; i++){
        if (arr[i]>fmax){
            tmax = smax;
            smax = fmax;
            fmax = arr[i];
        }
        if (arr[i]<fmax && arr[i]>smax){
            tmax = smax;
            smax = arr[i];
        }
        if (arr[i]<smax && arr[i]>tmax){
            tmax = arr[i];
        }
    }
    cout<<fmax<<" "<<smax<<" "<<tmax<<endl;

}


/*
*/