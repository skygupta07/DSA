#include <bits/stdc++.h>
using namespace std;


string decode_message(const std::string& encoded) {
    /*
    Write your logic here to decode the encoded message.
    Parameters:
        encoded (std::string): The encoded message as a string
    Returns:
        None
    */
    string result = "";
    int n = encoded.size();
    for(int i = 0; i < n; i++){
        if(encoded[i] <= 'n'){
            result += (char)('n' - encoded[i] + 'a');
        }
        else{
            result += (char)('z' - encoded[i] + 'o');
            i++;    // to skip #
        }
    }
    return result;
}

int main() {
    std::string encoded;
    std::getline(std::cin, encoded);
    
    // Call user logic function and print the output
    cout << decode_message(encoded);
    return 0;
}