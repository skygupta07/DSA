/*

class Solution {
public:
    
    void f(string digits, vector<string> &output, string &temp, vector <string> &pad, int idx){
        if (idx == digits.size()){
            output.push_back(temp);
            return;
        }
        string value = pad[digits[idx]-'0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            f(digits, output, temp, pad, idx+1);    // next index ke liye call laga di
            temp.pop_back();    // backtracking ka step
        }
    }

    vector<string> letterCombinations(string digits){
        if (digits.empty()){
            return {};  // curly braces representing empty vector of string 
        }

        vector <string> output;
        string temp;
        vector <string> pad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        f(digits,output,temp,pad,0);
        return output;
    }
};

*/