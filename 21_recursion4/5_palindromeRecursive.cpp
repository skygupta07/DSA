#include <iostream>
using namespace std;

bool isPalindrome(string s, int i, int j){
    if (i>j) return true; // base case

    // i at starting index and j at end -> if they crossed each other means we have visited
    // all the characters
    if (s[i]!=s[j]) return false;
    else return isPalindrome(s,i+1,j-1);
}


int main(){
    string s = "mom";
    cout<<isPalindrome(s,0,s.length()-1);
}

// we are just learning how to write recursive calls otherwise two pointer approach
// is quite better than this as recursion consumes space due to call stack...

