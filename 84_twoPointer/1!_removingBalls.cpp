/*

Problem Statement: Pick the Winner
Aryan and Ankit are playing a game with n balls placed in a line. 
Each ball has some positive integer value written on it. 

The rules of the game are as follows:

The players take turns alternately, with Aryan always starting first.
On each turn, a player can pick a ball from either the leftmost or the rightmost end of the current line.

The picked ball's value is added to that player's score.
Both players play optimally to maximize their own total score.
Given the list of integers on the balls, determine who will win the game 
(or if there is a tie, consider Aryan as the winner).

🔐 Input:

An integer n — number of balls (1 ≤ n ≤ 10⁵)
A list of n integers balls[i] — the value of each ball (1 ≤ balls[i] ≤ 10⁴)

🧾 Output:

Print "Aryan" if Aryan wins or ties.
Print "Ankit" if Ankit wins.


🧪 Sample Input:

5
4 2 9 7 1
✅ Sample Output:

Aryan


*/

#include <bits/stdc++.h>
using namespace std;

// A global DP table define ki gayi hai, lekin hum neeche vector<vector<int>> memo ka use kar rahe hain
// So yeh global dp ab redundant hai, remove kar sakte ho if not using
int dp[10001][10001];


// ✅ Yeh function recursively calculate karta hai ki kisi bhi subarray [l..r] mein
// player1 maximum kitna score le sakta hai, assuming dono players optimally khel rahe hain.
int maxScore(int l, int r, const vector <int> &balls, vector <vector<int>> &memo) {
    // Agar left pointer right se aage nikal gaya, matlab valid subarray nahi bacha
    if (l > r) return 0;

    // Memoization: agar pehle se answer calculated hai, to directly return kar do
    if (memo[l][r] != -1) return memo[l][r];

    // ⚔️ Option 1: Player1 left se ball uthata hai (balls[l])
    // Uske baad Ankit ka turn hoga, aur wo bhi optimally khelega
    // So hum minimum lete hain Ankit ke dono options me se (usko kam score mile to Aryan ko jyada mile)
    int takeLeft = balls[l] + min(
        maxScore(l + 2, r, balls, memo),    // Ankit ne bhi left liya
        maxScore(l + 1, r - 1, balls, memo) // Ankit ne right liya
    );

    // ⚔️ Option 2: Player1 right se ball uthata hai (balls[r])
    int takeRight = balls[r] + min(
        maxScore(l, r - 2, balls, memo),    // Ankit ne right liya
        maxScore(l + 1, r - 1, balls, memo) // Ankit ne left liya
    );

    // Final answer for subarray [l..r] will be max of both options
    return memo[l][r] = max(takeLeft, takeRight);
}

// ✅ Is function ka kaam hai final winner decide karna
string determine_winner(int n, const vector<int>& balls) {
    // Poore array ka total sum nikal liya
    int totalSum = accumulate(balls.begin(), balls.end(), 0);

    // Memoization table banayi - n x n size ki, saare elements initially -1
    vector<vector<int>> memo(n, vector<int>(n, -1));

    // Player1 (Aryan) ka maximum score calculate kiya using maxScore()
    int player1 = maxScore(0, n - 1, balls, memo);

    // Player2 (Ankit) ka score hoga: total - Aryan ka score
    int player2 = totalSum - player1;

    // Agar Aryan ka score jyada ya barabar hai, to Aryan jeeta
    // Warna Ankit jeeta
    return (player1 >= player2 ? "Aryan" : "Ankit");
}

int main() {
    int n;
    cin >> n;

    // Input array: balls ke upar likhe numbers store karein
    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    // determine_winner() se result calculate karke print kar diya
    cout << determine_winner(n, balls) << endl;

    return 0;
}



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