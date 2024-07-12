#include <iostream>
#include <vector>
using namespace std;
int main(){

}



string digitSum(string p){
    int sum = 0;
    for (char c : p){
        sum += c - '0';
    }
    return to_string(sum);
}


int superDigit(string n, int k) {
    string p = digitSum(n);
    
    long long initialSum = stoll(p) * k;
    p = to_string(initialSum);
    
    
    // reduce p to a single char
    while (p.length() > 1){
        p = digitSum(p);
    }
    // obviously here p.length == 1 hi ho raha hoga..
    return stoi(p);
}