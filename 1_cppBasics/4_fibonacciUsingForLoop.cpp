#include <iostream>
using namespace std;
int main(){
    //  1 1 2 3 5 8 13 21 34 55 89 
    int n;
    cout<<"enter n: ";
    cin>>n;

    int a = 1;
    int b = 1;
    int sum = a+b;

    for (int i=0; i<n; i++){
        if (i==0){
            cout<<a<<" ";
        }
        else if (i==1){
            cout<<b<<" ";

        }
        else{
            sum = a+b;
            a=b; 
            b=sum;
            cout<<sum<<" ";
        }
    }

}

