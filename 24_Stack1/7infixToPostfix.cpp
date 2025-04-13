#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return -1; // For non-operators
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string s) {
    stack <char> st;             // Stack for operators
    string postfix_exp = "";    // Output postfix string

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Agar character operand hai (like A-Z, a-z, 0-9), toh directly postfix mein daal do
        if (isalnum(ch)) {
            postfix_exp += ch;
        }

        // Agar '(' mila toh stack mein push karo
        else if (ch == '(') {
            st.push(ch);
        }

        // Agar ')' mila, toh stack se pop karo jab tak '(' na mil jaye
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix_exp += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // '(' ko bhi hata do
        }

        // Agar operator mila (like +, -, *, /, ^)
        else {
            while (!st.empty() && precedence(ch) <= precedence(st.top())) {
                postfix_exp += st.top();
                st.pop();
            }
            st.push(ch); // Current operator ko stack mein daal do
        }
    }

    // Stack mein bache sabhi operators ko postfix string mein daal do
    while (!st.empty()) {
        postfix_exp += st.top();
        st.pop();
    }

    return postfix_exp;
}

int main() {
    string infix_expression = "A*B-(C+D)+E";
    cout << "The postfix string is: " << infixToPostfix(infix_expression) << endl;
    return 0;
}
