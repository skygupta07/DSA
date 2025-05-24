#include <bits/stdc++.h>
using namespace std;

/*

Convert a non-negative integer num to its English words representation.

 
Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


*/

class Solution {
public:
    string digits[20] = {"Zero" , "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string intToStr(int n){
        if (n >= 1000000000){ // 8 zero - billion
            return intToStr(n/1000000000) + " Billion" + intToStr(n%1000000000);
        }
        else if (n >= 1000000){ // 6 zero - million
            return intToStr(n/1000000) + " Million" + intToStr(n%1000000);
        }
        else if (n >= 1000){
            return intToStr(n/1000) + " Thousand" + intToStr(n%1000);
        }
        else if (n >= 100){
            return intToStr(n/100) + " Hundred" + intToStr(n%100);
        }
        else if (n >= 20){
            return " " + tens[n/10] + intToStr(n%10);
        }

        else if (n >= 1){
            return " " + digits[n];
        }
        else{
            return "";
        }
    }


    string numberToWords(int num) {
        if (num == 0) return "Zero";
        else{
            string result = intToStr(num);
            return result.substr(1, result.length() - 1);
        }

    }
};