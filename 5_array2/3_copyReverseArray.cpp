#include <iostream>
using namespace std;
int main(){
    int arr[]={4,3,6,7,1};
    int barr[5];
    int j =sizeof(barr)/sizeof(barr[0]);
    for (int i=0; i<5; i++){
        barr[i] = arr[j-1];
        j--;
    }
    cout<<"arrays elements in reverse order are: ";
    for (int i=0; i<5; i++){
        cout<<barr[i]<<" ";
    }
}