#include <iostream>
using namespace std; 
int main(){
    int a,b;
    cout<<"enter a and b: ";
    cin>>a>>b;
    for (int i=a; i<=b; i++){
        if (i%2!=0){
            cout<<i<<" ";
        }
    }
    
    
}