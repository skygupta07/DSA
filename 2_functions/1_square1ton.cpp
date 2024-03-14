#include <iostream>
using namespace std;
void squarefn(int n){
    cout<<"square from 1 to n is: "<<endl;
    for (int i=1;i<=n;i++){
        cout<<i*i<<endl;
    }
}
    

int main(){

    int n;
    cout<<"enter n: ";
    cin>>n;
    squarefn(n);
}