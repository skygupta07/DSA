#include <bits/stdc++.h>
using namespace std;


int binToDec(string binNum){
    int n = binNum.length();

    int sum = 0;
    for (int i=0; i<n; i++){
        sum += (binNum[i] - '0')<<(n-1-i);
    }
    return sum;
}




int main(){
    string binNum = "0000010100";
    int decNum = binToDec(binNum);
    cout<<decNum<<endl;
}

/*
1 1 0 0 1 0 1 0 0 1 1 (binary number)

sum += 2power(n-idx-1)

return sum


*/

/*
HA BHAI CHARACTER SE INTEGER KARNE KE LIYE - '0'  KARNA padDAT HAI....

*/