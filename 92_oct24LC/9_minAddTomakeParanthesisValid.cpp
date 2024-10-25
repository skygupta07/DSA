class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int mismatch = 0;

        for (int i=0; i<s.length(); i++){
            if (s[i] == '(') open++;
            else{
                if (open > 0) open--;
                else mismatch++;
            }
        }

        return open + mismatch;
    }
};

/*
iterate over the string ,
count of open, close and mismatch brackets..
at any moment, maintain count of opening and closing brackets...
if at any you found closing bracket see if open > 0 open--;
else if open == 0 , and closing bracket aagya to mismatch++;
return mismatch + open

*/