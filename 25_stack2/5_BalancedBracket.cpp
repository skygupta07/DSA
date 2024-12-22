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


// LC 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s){
        stack <char> st;
        for (int i=0; i<s.length(); i++){
            // if incoming element is opening then push it into stack...
            if (s[i]=='(' || s[i]=='{' || s[i] == '[') st.push(s[i]);
            else{   //incoming char is closing bracket..
                if ( st.empty() or (st.top() == '(' && s[i]!=')') or (st.top() == '{' && s[i]!= '}')
                    or (st.top()=='[' && s[i]!=']') ) return false;
                
                // i.e. valid incoming char... so pop it...
                else st.pop();                
            }
        }
        return st.empty();
        
    }
};