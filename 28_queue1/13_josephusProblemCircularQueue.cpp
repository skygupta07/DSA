/*

There are 'N' persons standing in a circular queue. 
There is a number written on the back of the shirts of every person. 
One person among them has a ball in his hands and the number written on his shirt's back is 1. 
The number written on the shirt of every other person is 1 more than the number written on the shirt 
of the person standing to the left of him. We have also been provided with an integer 'K' 
denoting the jump parameter. They start playing a game. The game proceeds as follows:

1. If there is only one person remaining in the game then the game stops immediately 
and the person is declared the winner.
2. The player who currently has the ball in its hand passes the ball to the person standing to his right. 
3. Step 2 happens exactly 'K'-1 times.
4. The game pauses here and the person who has the ball in his hand currently has to pass the ball
to the person standing on his right and has to leave the game.

5. Again the game resumes with the remaining players.
You have been provided with positive integers 'N' and 'K'. Your task is to find the number written 
on the back of the winner when the game is played with 'N' members using the jump parameter 'K'.

For example:
N=4, K=2 -> K-1=1

The game starts with Person 1. He passes the ball to person 2. 
The game pauses here. Person 2 passes the ball to person 3 and leaves the game. 
Then the game resumes. Person 3 passes the ball to person 4. 
The game pauses here. Person 4 passes the ball to person 1 and leaves the game. 
Then the game resumes with person 1 having the ball in his hand. 
He passes the ball to person 3. The game pauses here. Person 3 passes the ball to person 1 
and leaves the game. Now only person 1 remains and the game stops here.


Note
You are not required to print anything, just implement the given function and return the number written 
on the shirt of the winner of the game.

Detailed explanation ( Input/output format, Notes, Images )

Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
1 <= K <= 10 ^ 9

Time limit: 1 second
Sample Input 1:
2
5
2
4
3
Sample Output 1:
3
1

Explanation of sample input 1:

For the first test case:
The game starts with Person 1. He passes the ball to person 2. 
The game pauses here. Person 2 passes the ball to person 3 and leaves the game. 
Then the game resumes. Person 3 passes the ball to person 4. The game pauses here. 
Person 4 passes the ball to person 5 and leaves the game. Then the game resumes with person 5 
having the ball in his hand. He passes the ball to person 1. The game pauses here. 
Person 1 passes the ball to person 3 and leaves the game. Then the game resumes with person 3 having
the ball in his hand. He passes the ball to person 5. The game pauses here. 
Person 5 passes the ball to person 3 and leaves the game. Now only person 3 remains and the game stops
here.

Hence, the winner of the game will be Person 3 and the answer will be 3.

For the second test case:
The game starts with Person 1. He passes the ball to person 2. 
Person 2 passes the ball to Person 3. The game pauses here. Person 3 passes the ball to Person 4 
and leaves the game. Then the game resumes. Person 4 passes the ball to person 1. Person 1 passes 
the ball to person 2.The game pauses here. Person 2 passes the ball to person 4 and leaves the game. 
Then the game resumes with Person 4 having the ball in his hand. He passes the ball to person 1. 
Person 1 passes the ball to Person 4. The game pauses here. Person 4 passes the ball to person 1 and 
leaves the game. Now only person 1 remains and the game stops here.

Hence, the winner of the game will be Person 1 and the answer will be 1.
Sample Input 2:
1
4
1
Sample Output 2:

*/


#include <bits/stdc++.h>
using namespace std;


// Function to find the winner in the game - ha for loop chalega.... 2 se leke N tak 
int findWinner(int N, int K) {
    // Start with 0-based indexing for Josephus problem
    int winner = 0; 

    for (int i = 2; i <= N; i++) {
        winner = (winner + K) % i;
    }

    // Convert to 1-based indexing
    return winner + 1;
}




int main() {
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << findWinner(N, K) << endl;
    }
    return 0;
}


