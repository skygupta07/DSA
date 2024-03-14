// you are given a string consisting of small alphabets. consider no repetition in the
// characters. Print all possible permutation of the string. ordering doesn't matter
#include <iostream>
#include <string>
using namespace std;


void permutation(string input, string output){
    if (input.size()==0){  // base case
        cout<<output<<"\n";
        return;
    }


    for (int i=0; i<input.size(); i++){  // iterating over each character
        char ch = input[i];
        string left = input.substr(0,i);
        string right = input.substr(i+1); // index i+1 se last tak ka string lega
        string ros = left + right; // rest of string
        permutation(ros, output + ch);
    }
}



int main(){
    permutation("abc", " ");
    return 0;
}















// every character of input string is given a chance to become first character of output string
// then next element is appended at its end...

