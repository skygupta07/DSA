// evaluateReversePolishNotation.cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int 
    evalRPN(vector <string> &tokens) {
        stack <string> st;

        for (int i=0; i<tokens.size(); i++){
            string str = tokens[i];

            // if  str is operator 
            if (str == "*" || str == "/" || str == "+" || str == "-"){
                int y = stoi(st.top());
                st.pop();

                int x = stoi(st.top());
                st.pop();

                if (str == "*") st.push(to_string(x * y));
                else if (str == "/") st.push(to_string(x / y));  
                else if (str == "+") st.push(to_string(x + y));  
                else if (str == "-") st.push(to_string(x - y));               
            }

            else{
                st.push(tokens[i]);
            }
        }

        return stoi(st.top());
    }
};

/*
jaise hi koi operator aaya kahi bhi aaye .... then hum just peeche ke do elements lenge and 
uske usko evaluate karenge iss operand ke saath


*/