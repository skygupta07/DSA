#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cout<<"enter number";
    cin>>n;

    int sum = 0;

    // sum of digit last digit walo mai greater than zero waala hi case 
    // dekha karo...

    while(n > 0){
        int ld = n%10;  // calculate last digit
        sum += ld;  // add the last digit to sum 
        n = n/10;   // divide the number...
    }
    
    cout<<"sum of digits is: "<<sum<<endl;
}