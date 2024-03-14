#include <iostream>
#include <vector>
using namespace std;

int f(int n){    // calculates all possible ways to sum upto n when a dice is thrown
    if (n==0) return 1; // empty subset count as 1 -> base case 
        // one way is mat feko dice...

    int sum = 0;
    // go and check each dice face
    for (int i=1; i<=6; i++){
        if (n-i < 0) break; // break because aage ke dice ke move se to aur negative result aaega
        sum += f(n-i);  // initial sum and final sum
                            
    }
    return sum;
}


int main(){
    int n;
    cout<<"enter n: \n";
    cin>>n;
    cout<<f(n)<<"\n";
    return 0;
}

