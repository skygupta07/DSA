#include <iostream>
using namespace std;
int main(){
    int arr[] = {7,4,6,2,9,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    int *ptr = &arr[0];
    cout<<ptr<<endl;  // ptr is a special kind of variable that stores the address
    cout<<*ptr<<endl; // now using dereference operator its value at that address can be printed..

    cout<<"printing all the elements of arrays using pointers: ";
    for (int i=0; i<size; i++){
        cout<<*ptr<<" ";
        ptr++; //ptr variable ko increment karna taki next address location pe jaa sake...jump of 4 bits though
    }
    cout<<endl;
    ptr = &arr[0];

    cout<<"printing all the elements of arrays using pointers: ";
    for (int i=0; i<size; i++){
        cout<<i[arr]<<" ";  //extra knowledge
        

    }


    
}