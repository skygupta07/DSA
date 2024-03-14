#include<iostream>
#include<stack>
using namespace std;

string removeDuplicate(string s){
    stack <char> st;
    st.push(s[0]);
    for (int i=1; i<s.length(); i++){
        if(st.top()!=s[i]){ //simply ek filter laga diya bas 
            st.push(s[i]);

        }
        
    }
    // meri required stack ban ke tayaar hai but print karwane ke liye better rahega ki 
    // me string ka hi use karu...

    s = "";
    // stack ko pura traverse karne ke trick:->
    while(st.size()>0){
        s += st.top();
        st.pop();  // important, nahi to hamesha top wala hi print karwata reh jaega...

    }
    // now uss string ko reverse bhi kar do...
    reverse(s.begin(),s.end());
    return s;
}



int main(){
    string s = "aaabbcddeefgggghiijjj";
    cout<<s<<endl;
    s = removeDuplicate(s);
    cout<<s<<endl;

}