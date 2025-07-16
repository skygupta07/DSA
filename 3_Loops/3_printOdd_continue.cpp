#include <iostream>
#include <vector>
using namespace std;



int main(){
    int n;
    cout<<"enter number:"<<endl;
    cin>>n;

    for (int i=0; i<n; i++){
        if (n%i == 0) continue;
        cout<<i<<endl;  
    }

}


// continue matlab bas current value of i ke liye ab mere neeche ka code mat chala dena...
// yarr is round ko skip kar do....abhi thoda time do recover karne ke liye....