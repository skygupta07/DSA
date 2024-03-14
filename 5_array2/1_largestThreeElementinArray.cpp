#include <iostream>
using namespace std;
int main(){
    int arr[7]={1,300,5,20,34,67,100};
    // printing the element of arrays...
    for (int i=0; i<7; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int fmax=arr[0];
    for (int i=0; i<7; i++){
        if (arr[i]>fmax){
            fmax=arr[i];
        }
    }

    cout<<"first maximum value is: "<<fmax<<endl;

    int smax= arr[0];
    for (int i=0; i<7; i++){
        if (arr[i]>smax && arr[i]!=fmax){
            smax = arr[i];
        }
    }

    cout<< "second maximum value is: "<<smax<<endl;

    int tmax = arr[0];
     for (int i=0; i<7; i++){
        if (arr[i]>tmax && arr[i]!=fmax && arr[i]!=smax){
        tmax = arr[i];
        }
    }

    cout<< "third maximum value is: "<<tmax<<endl;


}
