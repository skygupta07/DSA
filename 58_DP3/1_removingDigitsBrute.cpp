// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?

#include <iostream>
#include <vector>
#include <climits>
using namespace std;


vector<int> get_digits(int n){ // get digits of the number so that sabko ek ek baar subtract karke case 
                                    // banaye...
    vector<int> result;
    while(n>0){
        if(n%10 != 0){
            result.push_back(n%10);
        }
        n = n/10;
    }
    return result;
}

int f(int n){   //f(n) -> returns min. no. of steps to reduce n to zero,   
    if (n==0) return 0;
    if (n<=9) return 1;    // 8-8 = 0 in one step

    vector<int> d = get_digits(n);

    int result = INT_MAX;
    for (int i=0; i<d.size(); i++){
        result = min(result, f(n-d[i]));   // f kehta hai ki mujhe nahi pta ki n se zero 
                         // pahuchne me kitne steps lagenge mujhe to ye pta hai ki jitne bhi 
            // steps lagenge wo number me se digit ghate wale number se pucch lo...
    }
    return 1 + result;  // initial push taki waha pahuch sake..

}


int main(){
    int ans = f(27);
    cout<<ans<<endl;
}





/*
n is the only variable on which solution depends so apply single dimension dp
ek number pe khade hoke me ek ek karke saare number ghata ke dekh rha hu...jo bhi kam steps
dega wahi ans hoga

f(n) = 1 + min(f(n-d[i]))    
f(n) -> returns min. no. of steps to reduce n to zero,   
1 added because f(n-d[i]) tak pahuchane ka kiraya ek rupaya

// base case pure fn ko hamesha return nahi de dete, unka kaam hai ki jab ye wali
condition hit hogi tab meri taraf se ye value le jao...

since we have repetition of subproblem-> we can apply dp here


*/














