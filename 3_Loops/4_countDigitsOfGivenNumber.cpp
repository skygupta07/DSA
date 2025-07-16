#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cout<<"enter number: "<<endl;
    cin>>n;

    // 58934030524
    int digits = 0;
    int a = n;

    while (n > 0){
        n = n/10;
        digits++;
    }

    if (a==0) cout<<1<<endl;
    else cout<<"number of digits in number is: "<<digits<<endl;

}