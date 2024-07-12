#include <iostream>
#include <vector>
using namespace std;


int main(){
    cout<<"enter n: ";
    int n;
    cin>>n;


    int curr = 1;
    for (int i=0; i<=n; i++){
        cout<<curr<<" ";
        curr = curr*(n-i)/(i+1);
    }
    cout<<endl;
}





/*

0c0

1c0 1c1

2c0 2c1 2c2 

3c0 3c1 3c2 3c3 

4c0 4c1 4c2 4c3 4c4



ncr = nfact/rfact*(n-r)fact

nCr+1 = (n-r)/(r+1) * ncr

*/