#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;  // no
    cout<<"enter number of rows: "<<endl;
    cin>>n;

    cout<<endl;
    cout<<"number pyramid Palindrome....";
    cout<<endl;

    for (int i=1; i<=n; i++){
        // spaces (inverted triangle) ka loop
        for (int j=1; j<=n-i; j++) cout<<"  ";

        // increasing number ka loop...
        for (int k=1; k<=i; k++) cout<<k<<" ";
        
        // decreasing loop
        for (int l=i-1; l>=1; l--) cout<<l<<" ";

        // chipakne nahi dena...
        cout<<endl;
    }


}