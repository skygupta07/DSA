#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string s){
    stack <char> st; // arey jaise vector <int> v;
    for (int i=0; i<s.length(); i++){
        if (s[i]=='('){
            st.push(s[i]);  // if opening bracket is encountered... push it into stack
        }
        else{ // s[i]==')' closing bracket
            if(st.size()==0) return false;
            else{ //  if closing bracket is encountered when there is open bracket already there in stack then simply 
                        // pop the corresponding opening bracket..
                st.pop();

            }


        }
    }
    // puri string ko traverse karne ke baad aur saare push pop operation karne ke 
    // baad agar stack khali hai matlab sabke pair ban gye honge..
    if(st.size()==0){
        return true;
    }
    else return false;

}

int main(){
    string s = "((())))";
    cout<<isBalanced(s)<<endl;
    
}