#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){    // two pointer
    int i=0;
    int j=s.length()-1;

    while (i++ < j--){
        if (s[i]!=s[j]) return false;
    }
    
    return true;
}


int main(){
    string s = "racecar";
    cout<<isPalindrome(s);
}


/*
nitin , racecar, mom -> palindrome hai..(palindrome matlab ulta seedha sab ek barabar)
*/