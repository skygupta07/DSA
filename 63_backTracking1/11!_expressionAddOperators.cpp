#include <bits/stdc++.h>
using namespace std;


/*

Given a string num that contains only digits and an integer target, 
return all possibilities to insert the binary operators '+', '-', and/or '*' 
between the digits of num so that the resultant expression evaluates to the target value.

Note that operands in the returned expressions should not contain leading zeros.


Example 1:

Input: num = "123", target = 6
Output: ["1*2*3","1+2+3"]
Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.


Example 2:

Input: num = "232", target = 8
Output: ["2*3+2","2+3*2"]
Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.


Example 3:

Input: num = "3456237490", target = 9191
Output: []
Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
 

Constraints:

1 <= num.length <= 10
num consists of only digits.
-2pow31 <= target <= 2pow31 - 1


*/




class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string currentExpression; // backtracking ke question mai ye one bottle down har jagah likhna is very much compulsory..
        

                            // index, currValue, lastValue
        backtrack(num, target, 0, 0, 0, currentExpression, result);
        return result;
    }

private:

    void backtrack(const string& num, int target, int index, long long currentValue, long long lastValue, string& currentExpression, vector<string>& result) {
        
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(currentExpression);
            }
            return;
        }


        for (int i = index; i < num.size(); ++i) {
            // Avoid leading zeros
            if (i > index && num[index] == '0') break;

            string currentNumStr = num.substr(index, i - index + 1);
            long long currentNum = stoll(currentNumStr);

            if (index == 0) {
                // First number, no operator needed
                currentExpression = currentNumStr;
                backtrack(num, target, i + 1, currentNum, currentNum, currentExpression, result);
            }
            
            else {
                // Try addition
                currentExpression += '+' + currentNumStr;
                backtrack(num, target, i + 1, currentValue + currentNum, currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() - currentNumStr.size() - 1); // Remove last added operator and number

                // Try subtraction
                currentExpression += '-' + currentNumStr;
                backtrack(num, target, i + 1, currentValue - currentNum, -currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() - currentNumStr.size() - 1);

                // Try multiplication
                currentExpression += '*' + currentNumStr;
                backtrack(num, target, i + 1, currentValue - lastValue + (lastValue * currentNum), lastValue * currentNum, currentExpression, result);
                currentExpression.erase(currentExpression.size() - currentNumStr.size() - 1);
            }
            
        }
    }
};