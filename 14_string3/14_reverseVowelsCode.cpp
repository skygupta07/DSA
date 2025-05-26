#include <bits/stdc++.h>
using namespace std;


int user_logic(const std::string &s) {
    int n = s.length();

    // Step 1: Extract vowels
    vector <char> vowels;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels.push_back(s[i]);
        }
    }

    // Step 2: Reverse the vowels only and replace in the string (using simple pointer)
    string temp = s; // Copy of the original string
    int ptr = vowels.size() - 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            temp[i] = vowels[ptr--];
        }
    }

    // Step 3: Find occurrences of "code" in the modified string
    int count = 0;
    
    for (int i = 0; i <= n - 4; i++) {
        if (temp.substr(i, 4) == "code") {
            count++;
        }
    }

    return count;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    // Call user logic function and print the output
    int result = user_logic(s);
    std::cout << result << std::endl;
    return 0;
}
