#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    
    vector <int> v(3,5); // v(size of vector, element which will be copied vector size times)
   // 3 size ka vector bana hai jisme ki har element 5 hoga..
    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;

    vector <int> v1(arr,arr+n1); // imp
    // syntax to copy the array element into vector
    // vector <int> vector'sname (array , array+arrayKaSize)
    
    for (int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;




}