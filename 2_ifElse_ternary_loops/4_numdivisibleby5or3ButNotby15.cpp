#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    if ( (n%5==0 || n%3==0) && (n%15 != 0) ) cout<<"strong number"<<endl;
    else cout<<"fuddu number"<<endl;
}


/*

if (n%5==0 || n%3==0){
    if(n%15 != 0)  cout<<"strong number"<<endl;
    else cout<<"fuddu number"<<endl;
}
else cout<<"fuddu number"<<endl;

*/