#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void rev(string s){ // using stack
    stack <char> st;
    for (int i=0; i<s.size(); i++){
        st.push(s[i]);  
    }

    while (st.size()>0){    // or while(!st.empty())
        // top pop push
        char x = st.top();
        cout<<x;
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s = "akash";
    rev(s);
}