#include <bits/stdc++.h>
using namespace std;

int count_distinct_words_by_removing_pairs(const std::string& message) {
    

    int n = message.length();

    if (n == 2) return 1;

    int left = 0;
    int right = 1;

    set <string> st;

    while(right <= n-1){
        st.insert (to_string((message[left] + message[right])));
        left++;
        right++;
    }

    return st.size();

}

/*
create distinct messages by separating any two consecutive boxes at a time.
*/

int main() {
    std::string message;
    std::getline(std::cin, message);
    
    int result = count_distinct_words_by_removing_pairs(message);
    std::cout << result << std::endl;
    return 0;
}