// checkPalindrome.cpp

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    if (i>j) return true;   // hamesha base case pehle...
    
    if (s[i] == s[j]) return isPalindrome(s,i+1,j-1);
    else return false;
}

int main(){
    string s = "11211";
    int n = s.length();
    bool ans = isPalindrome(s,0,n-1);
    cout<<ans<<endl;
}   

// two pointer se recursion implement kiya.....
// for multiple recursion first one completes then second come into picture... 
// nitin is palindrome..
// okay now I understood the concept of palindrome...


