// prettyJSON.cpp

#include <bits/stdc++.h>
using namespace std;

vector<string> prettyJSON(string &str) {
    // Write your code here.
    vector <string> ans;

    string s = "";

    int indentLevel = 0;

    for (auto ch: str) {

        if (ch == '[' || ch == '{'){

            if (!s.empty()){
                ans.push_back(s);
                s = "";
            }

            s += string(indentLevel*4, ' ') + ch;
            ans.push_back(s);

            s = "";
            indentLevel++;
        } 

        else if (ch == ']' || ch == '}'){
            
            if (!s.empty()){
                ans.push_back(s);
                s = "";
            }

            indentLevel--;
            s += string(indentLevel*4, ' ') + ch;
        } 

        else if (ch == ','){
            s += ch;
            ans.push_back(s);
            s = "";
        }

        else{
            
            if (s.empty()){
                s += string(indentLevel*4 , ' ');
            }

            s += ch;
        }
    }

    // push any remaining string
    if (!s.empty()) ans.push_back(s);

    return ans;
}



