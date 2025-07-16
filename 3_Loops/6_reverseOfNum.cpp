#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n;
    cout<<"enter number"<<endl;
    cin>>n;

    // 4925 -> 5294 === 5*10 +2   then 52*10 + 9 then 529*10 + 4 

    int rev = 0;

    while (n > 0){

        rev = rev*10;   // step1 -> place value set karega..
        int ld = n%10;  // step2 -> calculating last digit
        
        rev += ld;      // step3 -> calculating its contribution
        n = n/10;       // step4 -> while hai to number ko bhi to set karna hoga..
    }

    cout<<rev<<endl;
}