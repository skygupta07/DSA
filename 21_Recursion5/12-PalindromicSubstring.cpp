/*
wrong approach.....


class Solution {
public:

    void generateSub(string &s, vector <string> substr, string &auxStr, int idx){
        int n = s.length();

        if (idx == n){
            substr.push_back(auxStr);
            return;
        }

        generateSub(s,substr,auxStr,idx+1);
        auxStr.push_back(s[idx]);
        generateSub(s, substr, auxStr, idx + 1);
    }

    bool isPalindrome(string &str){
        int i = 0;
        int j = str.length() - 1;
        
        while (i<=j){
            if (str[i] == str[j]){
                i++;
                j--;
            }
            else return false;   
        }
        return true;
    }

    int countSubstrings(string s){
        int count = 0;
        int n = s.length();
        vector <string> substr(pow(2,n), "");

        
        string auxStr;
        generateSub(s, substr, auxStr , 0);

        for (int i=0; i<substr.size(); i++){
            if (isPalindrome(substr[i])) count++;
        }
        return count;

    }
};

/*
int count
generate substring -> recursion take it don't take it...
for single length string -> count + = length
generate other substrings and apply check of palindrome if palindrome then count++

*/