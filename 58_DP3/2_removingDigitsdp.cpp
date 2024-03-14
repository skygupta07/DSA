// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


vector<int> get_digits(int n){
    vector<int> result;
    while(n>0){
        if(n%10 != 0){
            result.push_back(n%10);
        }
        n = n/10;
    }
    return result;
}


vector<int> dp;    // change1 -> initialise dp
int f(int n){   //f(n) -> returns min. no. of steps to reduce n to zero,   
    if (n==0) return 0;
    if (n<=9) return 1;
    if (dp[n]!= -1) return dp[n];  // change2 -> base case ke baad turant check kiya 
                                    // ki kahi pehle hi to compute nahi kiya hua..

    vector<int> d = get_digits(n);
    int result = INT_MAX;
    for (int i=0; i<d.size(); i++){
        result = min(result, f(n-d[i]));
    }  
    return dp[n] = 1 + result;   // change3-> ab tum dp ki hi help se return karo
 
}


int main(){
    
    dp.clear();   // change4 -> to clear the garbage value if present....
    dp.resize(1000005 , -1);  // change 5-> dp ka size constraint se 5 upar ka i.e. to
                            // to be on safe side  as constraint:  1<n<10^6  
    int ans = f(27);
    cout<<ans<<endl;
    
}