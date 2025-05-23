#include <bits/stdc++.h>
using namespace std;

string determine_winner(int n, const vector<int>& balls) {
    int left = 0;
    int right = n -1;

    int player1 = 0;
    int player2 = 0;

    bool turn = 1;  // 1 means player1 turn

    while (left <= right){
        if (balls[right] >= balls[left]){
            if (turn){
                player1 += balls[right];
            }
            else player2 + balls[right];
            right--;
        }

        else{
            if (turn){
                player1 += balls[left];
            }
            else player2 + balls[left];
            left++;
        }

        turn = !turn;
    }

    if (player1 >= player2) return "Aryan";
    else return "Ankit";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> balls[i];
    }
    
    std::string result = determine_winner(n, balls);
    std::cout << result << std::endl;
    return 0;
}