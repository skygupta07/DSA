#include <bits/stdc++.h>
using namespace std;


int main(){
    int a[5] = {7};
    cout<<a[3]<<"\n";   // prints 0

    int b[8] = {4567};
    cout<<b[3]<<"\n";

    int n;
    cout<<"enter size of array: "<<"\n";
    cin>>n;

    int arr[n];
    memset(arr, 0, sizeof(arr));    // bas zero ya -1 se hi puri array ko initialise kar sakte ho.,,,,

    // vector <int> v(8, -3);   // 8 size ka vector aur sabko -3 se initialise kar diya...

    cout<<arr[5]<<endl;

}



/*
it is used to fill a block of memory with a particular value.

#include <cstring> 
memset(variable name, values, sizeof(variable name));

memset mai zero or -1 ke alawa kucch bhi fill karoge to error aaega....

*/




